// Copyright Ark. Ark Log Player — subsystem implementation.

#include "ArkLogPlayerSubsystem.h"
#include "ArkJsonParser.h"
#include "Engine/GameInstance.h"
#include "Containers/Ticker.h"

void UArkLogPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TickerHandle_ = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UArkLogPlayerSubsystem::TickTicker));
}

void UArkLogPlayerSubsystem::Deinitialize()
{
	if (TickerHandle_.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(TickerHandle_);
		TickerHandle_.Reset();
	}
	Stop();
	Super::Deinitialize();
}

bool UArkLogPlayerSubsystem::TickTicker(float DeltaTime)
{
	Tick(DeltaTime);
	return true; // keep ticking
}

bool UArkLogPlayerSubsystem::LoadLog(FString FilePath, FString& OutError)
{
	Stop();
	Frames_.Reset();
	VehicleFrameIndex_.Reset();
	TimeNsMin_ = 0;
	TimeNsMax_ = 0;
	PlaybackTimeNs_ = 0.0;

	if (!FArkJsonParser::ParseFile(FilePath, Frames_, OutError))
	{
		return false;
	}

	if (Frames_.Num() == 0)
	{
		OutError = TEXT("No frames in file");
		return false;
	}

	TimeNsMin_ = Frames_[0].TimestampNs;
	TimeNsMax_ = Frames_.Last().TimestampNs;

	// Build VehicleId -> sorted frame indices (indices into Frames_ where that vehicle has state)
	for (int32 FrameIdx = 0; FrameIdx < Frames_.Num(); ++FrameIdx)
	{
		for (const FArkVehicleState& V : Frames_[FrameIdx].Vehicles)
		{
			TArray<int32>& Indices = VehicleFrameIndex_.FindOrAdd(V.VehicleId);
			Indices.Add(FrameIdx);
		}
	}

	PlaybackTimeNs_ = static_cast<double>(TimeNsMin_);
	OnLogLoaded.Broadcast();
	return true;
}

void UArkLogPlayerSubsystem::Play()
{
	bIsPlaying = true;
}

void UArkLogPlayerSubsystem::Pause()
{
	bIsPlaying = false;
}

void UArkLogPlayerSubsystem::Stop()
{
	bIsPlaying = false;
	PlaybackTimeNs_ = static_cast<double>(TimeNsMin_);
}

void UArkLogPlayerSubsystem::SeekTo(float TimeSeconds)
{
	const double Ns = static_cast<double>(TimeNsMin_) + static_cast<double>(TimeSeconds) * 1e9;
	PlaybackTimeNs_ = FMath::Clamp(Ns, static_cast<double>(TimeNsMin_), static_cast<double>(TimeNsMax_));
}

float UArkLogPlayerSubsystem::GetDurationSeconds() const
{
	if (TimeNsMax_ <= TimeNsMin_) { return 0.0f; }
	return static_cast<float>(static_cast<double>(TimeNsMax_ - TimeNsMin_) / 1e9);
}

TArray<int32> UArkLogPlayerSubsystem::GetVehicleIds() const
{
	TArray<int32> Ids;
	for (const auto& Pair : VehicleFrameIndex_)
	{
		Ids.Add(Pair.Key);
	}
	return Ids;
}

bool UArkLogPlayerSubsystem::GetVehiclePath(int32 VehicleId, TArray<FVector>& OutPoints, float MinSampleStepSec) const
{
	OutPoints.Reset();

	const TArray<int32>* Indices = VehicleFrameIndex_.Find(VehicleId);
	if (!Indices || Indices->Num() == 0)
	{
		return false;
	}

	const int64 MinSampleStepNs = MinSampleStepSec > 0.0f
		? static_cast<int64>(static_cast<double>(MinSampleStepSec) * 1e9)
		: 0;
	int64 LastAcceptedTimestampNs = TNumericLimits<int64>::Min();

	for (const int32 FrameIdx : *Indices)
	{
		if (!Frames_.IsValidIndex(FrameIdx))
		{
			continue;
		}

		const FArkFrame& Frame = Frames_[FrameIdx];
		if (MinSampleStepNs > 0 && LastAcceptedTimestampNs != TNumericLimits<int64>::Min())
		{
			const int64 Delta = Frame.TimestampNs - LastAcceptedTimestampNs;
			if (Delta < MinSampleStepNs)
			{
				continue;
			}
		}

		for (const FArkVehicleState& V : Frame.Vehicles)
		{
			if (V.VehicleId == VehicleId)
			{
				OutPoints.Add(V.Position + PlaybackWorldOffset);
				LastAcceptedTimestampNs = Frame.TimestampNs;
				break;
			}
		}
	}

	return OutPoints.Num() > 0;
}

bool UArkLogPlayerSubsystem::GetInterpolatedVehicleState(int32 VehicleId, FArkVehicleState& OutState) const
{
	const TArray<int32>* Indices = VehicleFrameIndex_.Find(VehicleId);
	if (!Indices || Indices->Num() == 0)
	{
		return false;
	}

	const int64 T = static_cast<int64>(PlaybackTimeNs_);

	// Binary search for bracketing frame indices
	int32 Lo = 0;
	int32 Hi = Indices->Num() - 1;
	while (Lo < Hi - 1)
	{
		const int32 Mid = (Lo + Hi) / 2;
		const int64 Tm = Frames_[(*Indices)[Mid]].TimestampNs;
		if (Tm <= T) { Lo = Mid; }
		else { Hi = Mid; }
	}

	const int32 IdxLo = (*Indices)[Lo];
	const int32 IdxHi = (Hi != Lo) ? (*Indices)[Hi] : IdxLo;
	const FArkFrame& FrameLo = Frames_[IdxLo];
	const FArkFrame& FrameHi = Frames_[IdxHi];

	const FArkVehicleState* StateLo = nullptr;
	const FArkVehicleState* StateHi = nullptr;
	for (const FArkVehicleState& V : FrameLo.Vehicles)
	{
		if (V.VehicleId == VehicleId) { StateLo = &V; break; }
	}
	for (const FArkVehicleState& V : FrameHi.Vehicles)
	{
		if (V.VehicleId == VehicleId) { StateHi = &V; break; }
	}

	if (!StateLo)
	{
		return false;
	}

	if (!StateHi || IdxLo == IdxHi || FrameHi.TimestampNs == FrameLo.TimestampNs)
	{
		OutState = *StateLo;
		OutState.Position += PlaybackWorldOffset;
		OutState.Rotation = (OutState.Rotation * PlaybackRotationOffset.Quaternion()).GetNormalized();
		OutState.TimestampNs = T;
		return true;
	}

	const double Denom = static_cast<double>(FrameHi.TimestampNs - FrameLo.TimestampNs);
	const double Alpha = Denom > 0.0
		? FMath::Clamp((static_cast<double>(T) - static_cast<double>(FrameLo.TimestampNs)) / Denom, 0.0, 1.0)
		: 0.0;

	OutState.VehicleId = VehicleId;
	OutState.Position = FMath::Lerp(StateLo->Position, StateHi->Position, static_cast<float>(Alpha)) + PlaybackWorldOffset;
	OutState.Rotation = (
		FQuat::Slerp(StateLo->Rotation, StateHi->Rotation, static_cast<float>(Alpha)) *
		PlaybackRotationOffset.Quaternion()
	).GetNormalized();
	OutState.TimestampNs = T;
	return true;
}

void UArkLogPlayerSubsystem::Tick(float DeltaSeconds)
{
	if (!bIsPlaying || Frames_.Num() == 0)
	{
		return;
	}

	PlaybackTimeNs_ += static_cast<double>(DeltaSeconds) * 1e9 * static_cast<double>(PlaybackSpeed);
	if (PlaybackTimeNs_ >= static_cast<double>(TimeNsMax_))
	{
		PlaybackTimeNs_ = static_cast<double>(TimeNsMax_);
		// Optional: Pause(); for one-shot
	}
	PlaybackTimeNs_ = FMath::Clamp(PlaybackTimeNs_, static_cast<double>(TimeNsMin_), static_cast<double>(TimeNsMax_));

	PlaybackTimeSec = static_cast<float>((PlaybackTimeNs_ - static_cast<double>(TimeNsMin_)) / 1e9);
	OnPlaybackTick.Broadcast(PlaybackTimeSec);
}
