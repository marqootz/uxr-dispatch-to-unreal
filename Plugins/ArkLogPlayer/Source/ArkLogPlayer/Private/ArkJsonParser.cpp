// Copyright Ark. Ark Log Player — parse .jsonl → TArray<FArkFrame>.

#include "ArkJsonParser.h"
#include "ArkCoordinates.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

bool FArkJsonParser::ParseFile(const FString& FilePath, TArray<FArkFrame>& OutFrames, FString& OutError)
{
	OutFrames.Reset();
	FString Content;
	if (!FFileHelper::LoadFileToString(Content, *FilePath))
	{
		OutError = FString::Printf(TEXT("Failed to open file: %s"), *FilePath);
		return false;
	}

	TArray<FString> Lines;
	Content.ParseIntoArray(Lines, TEXT("\n"), true);

	for (int32 i = 0; i < Lines.Num(); ++i)
	{
		const FString& Line = Lines[i];
		if (Line.IsEmpty()) { continue; }

		FArkFrame Frame;
		FString LineError;
		if (ParseLine(Line, Frame, LineError))
		{
			OutFrames.Add(MoveTemp(Frame));
		}
		// Skip malformed lines; optional: append LineError to OutError for first failure
	}

	// Sort by timestamp
	OutFrames.Sort([](const FArkFrame& A, const FArkFrame& B) { return A.TimestampNs < B.TimestampNs; });

	return true;
}

bool FArkJsonParser::ParseLine(const FString& Line, FArkFrame& OutFrame, FString& OutError)
{
	OutError.Empty();
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Line);
	TSharedPtr<FJsonObject> Root;
	if (!FJsonSerializer::Deserialize(Reader, Root) || !Root.IsValid())
	{
		OutError = TEXT("Invalid JSON");
		return false;
	}

	// Timestamp: primary = time.local_time (VehicleStatus); optional = _ark_metadata.logged_timestamp; fallback = stamp.local_time (other channels)
	int64 TimestampNs = 0;
	const TSharedPtr<FJsonObject>* TimeObj = nullptr;
	if (Root->TryGetObjectField(TEXT("time"), TimeObj) && TimeObj && (*TimeObj).IsValid() && (*TimeObj)->TryGetNumberField(TEXT("local_time"), TimestampNs))
	{
		// VehicleStatus: time.local_time (int64, nanoseconds)
	}
	else
	{
		const TSharedPtr<FJsonObject>* MetaObj = nullptr;
		if (Root->TryGetObjectField(TEXT("_ark_metadata"), MetaObj) && MetaObj && (*MetaObj).IsValid() && (*MetaObj)->TryGetNumberField(TEXT("logged_timestamp"), TimestampNs))
		{
			// With --include-message-metadata: pipeline time
		}
		else
		{
			const TSharedPtr<FJsonObject>* StampObj = nullptr;
			if (Root->TryGetObjectField(TEXT("stamp"), StampObj) && StampObj && (*StampObj).IsValid() && (*StampObj)->TryGetNumberField(TEXT("local_time"), TimestampNs))
			{
				// Other channel types that use stamp
			}
			else
			{
				OutError = TEXT("No timestamp: expected time.local_time, _ark_metadata.logged_timestamp, or stamp.local_time");
				return false;
			}
		}
	}

	OutFrame.TimestampNs = static_cast<int64>(TimestampNs);
	OutFrame.Vehicles.Reset();

	auto ParseVehicleStateObject = [&OutFrame](const TSharedPtr<FJsonObject>& Status) -> bool
	{
		int32 Id = 0;
		if (!Status.IsValid() || !Status->TryGetNumberField(TEXT("id"), Id))
		{
			return false;
		}

		const TSharedPtr<FJsonObject>* StateObj = nullptr;
		if (!Status->TryGetObjectField(TEXT("state"), StateObj) || !StateObj || !(*StateObj).IsValid())
		{
			return false;
		}

		const TSharedPtr<FJsonObject>* PoseObj = nullptr;
		if (!(*StateObj)->TryGetObjectField(TEXT("pose"), PoseObj) || !PoseObj || !(*PoseObj).IsValid())
		{
			return false;
		}

		// translation: x, y, z (meters)
		FVector TranslationM(0.0f, 0.0f, 0.0f);
		const TSharedPtr<FJsonObject>* TransObj = nullptr;
		if ((*PoseObj)->TryGetObjectField(TEXT("translation"), TransObj) && TransObj && (*TransObj).IsValid())
		{
			double X = 0.0, Y = 0.0, Z = 0.0;
			(*TransObj)->TryGetNumberField(TEXT("x"), X);
			(*TransObj)->TryGetNumberField(TEXT("y"), Y);
			(*TransObj)->TryGetNumberField(TEXT("z"), Z);
			TranslationM.Set(static_cast<float>(X), static_cast<float>(Y), static_cast<float>(Z));
		}

		// rotation: x, y, z, w (Hamilton quaternion)
		float Qx = 0.0f, Qy = 0.0f, Qz = 0.0f, Qw = 1.0f;
		const TSharedPtr<FJsonObject>* RotObj = nullptr;
		if ((*PoseObj)->TryGetObjectField(TEXT("rotation"), RotObj) && RotObj && (*RotObj).IsValid())
		{
			(*RotObj)->TryGetNumberField(TEXT("x"), Qx);
			(*RotObj)->TryGetNumberField(TEXT("y"), Qy);
			(*RotObj)->TryGetNumberField(TEXT("z"), Qz);
			(*RotObj)->TryGetNumberField(TEXT("w"), Qw);
		}

		FArkVehicleState State;
		State.VehicleId = Id;
		State.Position = ArkCoordinates::SourceToUnreal(TranslationM);
		State.Rotation = ArkCoordinates::SourceToUnreal(Qx, Qy, Qz, Qw);
		State.TimestampNs = OutFrame.TimestampNs;
		OutFrame.Vehicles.Add(MoveTemp(State));
		return true;
	};

	const TArray<TSharedPtr<FJsonValue>>* StatusesArray = nullptr;
	if (Root->TryGetArrayField(TEXT("statuses"), StatusesArray) && StatusesArray)
	{
		for (const TSharedPtr<FJsonValue>& StatusValue : *StatusesArray)
		{
			const TSharedPtr<FJsonObject>* StatusObj = nullptr;
			if (!StatusValue.IsValid() || !StatusValue->TryGetObject(StatusObj) || !StatusObj || !(*StatusObj).IsValid())
			{
				continue;
			}
			ParseVehicleStateObject(*StatusObj);
		}
	}
	else
	{
		// Single VehicleStatus schema: id/state at root level (no statuses[] array)
		ParseVehicleStateObject(Root);
	}

	return true;
}
