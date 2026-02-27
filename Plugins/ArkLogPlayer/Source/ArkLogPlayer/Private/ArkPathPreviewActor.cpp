// Copyright Ark. Ark Log Player — editor/runtime path preview actor.

#include "ArkPathPreviewActor.h"

#include "ArkJsonParser.h"
#include "ArkTypes.h"
#include "Components/SplineComponent.h"

AArkPathPreviewActor::AArkPathPreviewActor()
{
	PrimaryActorTick.bCanEverTick = false;

	PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("PathSpline"));
	SetRootComponent(PathSpline);
	PathSpline->SetMobility(EComponentMobility::Movable);
	PathSpline->bDrawDebug = true;
}

void AArkPathPreviewActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (bAutoRebuild)
	{
		RebuildPreview();
	}
}

void AArkPathPreviewActor::RebuildPreview()
{
	if (!PathSpline)
	{
		return;
	}

	TArray<FVector> Points;
	FString Error;
	if (!BuildPoints(Points, Error))
	{
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("ArkPathPreviewActor '%s' build failed. VehicleId=%d FilePath='%s' Error='%s'"),
			*GetName(),
			VehicleId,
			*FilePath,
			*Error
		);
		if (bClearOnFailure)
		{
			PathSpline->ClearSplinePoints(true);
		}
		return;
	}

	PathSpline->ClearSplinePoints(false);
	for (const FVector& P : Points)
	{
		PathSpline->AddSplinePoint(P, ESplineCoordinateSpace::World, false);
	}
	PathSpline->UpdateSpline();

	UE_LOG(
		LogTemp,
		Display,
		TEXT("ArkPathPreviewActor '%s' built %d points. VehicleId=%d FilePath='%s'"),
		*GetName(),
		Points.Num(),
		VehicleId,
		*FilePath
	);
}

bool AArkPathPreviewActor::BuildPoints(TArray<FVector>& OutPoints, FString& OutError) const
{
	OutPoints.Reset();

	if (FilePath.IsEmpty())
	{
		OutError = TEXT("FilePath is empty.");
		return false;
	}
	if (VehicleId == 0)
	{
		OutError = TEXT("VehicleId is 0. Set a valid vehicle id (e.g. 301).");
		return false;
	}

	TArray<FArkFrame> Frames;
	if (!FArkJsonParser::ParseFile(FilePath, Frames, OutError))
	{
		return false;
	}
	if (Frames.Num() == 0)
	{
		OutError = TEXT("No frames parsed from file.");
		return false;
	}

	const int64 MinStepNs = MinSampleStepSec > 0.0f
		? static_cast<int64>(static_cast<double>(MinSampleStepSec) * 1e9)
		: 0;
	int64 LastAcceptedNs = TNumericLimits<int64>::Min();

	for (const FArkFrame& Frame : Frames)
	{
		if (MinStepNs > 0 && LastAcceptedNs != TNumericLimits<int64>::Min())
		{
			const int64 Delta = Frame.TimestampNs - LastAcceptedNs;
			if (Delta < MinStepNs)
			{
				continue;
			}
		}

		for (const FArkVehicleState& V : Frame.Vehicles)
		{
			if (V.VehicleId == VehicleId)
			{
				OutPoints.Add(V.Position + WorldOffset);
				LastAcceptedNs = Frame.TimestampNs;
				if (OutPoints.Num() >= MaxPoints)
				{
					return true;
				}
				break;
			}
		}
	}

	if (OutPoints.Num() == 0)
	{
		OutError = FString::Printf(TEXT("No points found for VehicleId=%d"), VehicleId);
		return false;
	}
	return true;
}

