// Copyright Ark. Ark Log Player — editor/runtime path preview actor.

#include "ArkPathPreviewActor.h"

#include "ArkJsonParser.h"
#include "ArkTypes.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/CollisionProfile.h"

AArkPathPreviewActor::AArkPathPreviewActor()
{
	PrimaryActorTick.bCanEverTick = false;

	PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("PathSpline"));
	SetRootComponent(PathSpline);
	PathSpline->SetMobility(EComponentMobility::Movable);
	PathSpline->bDrawDebug = bShowSplineDebug;
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

	PathSpline->bDrawDebug = bShowSplineDebug;

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
			ClearRoadMeshes();
		}
		return;
	}

	PathSpline->ClearSplinePoints(false);
	for (const FVector& P : Points)
	{
		PathSpline->AddSplinePoint(P, ESplineCoordinateSpace::World, false);
	}
	PathSpline->UpdateSpline();
	RebuildRoadMeshes();

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

void AArkPathPreviewActor::ClearRoadMeshes()
{
	for (USplineMeshComponent* MeshComp : RoadSplineMeshes)
	{
		if (IsValid(MeshComp))
		{
			MeshComp->DestroyComponent();
		}
	}
	RoadSplineMeshes.Reset();
}

void AArkPathPreviewActor::RebuildRoadMeshes()
{
	ClearRoadMeshes();

	if (!bGenerateRoadMesh || !PathSpline || !RoadMesh)
	{
		return;
	}

	const int32 NumSplinePoints = PathSpline->GetNumberOfSplinePoints();
	if (NumSplinePoints < 2)
	{
		return;
	}

	for (int32 PointIndex = 0; PointIndex < NumSplinePoints - 1; ++PointIndex)
	{
		USplineMeshComponent* MeshComp = NewObject<USplineMeshComponent>(this);
		if (!MeshComp)
		{
			continue;
		}

		MeshComp->SetMobility(EComponentMobility::Movable);
		MeshComp->SetStaticMesh(RoadMesh);
		MeshComp->SetForwardAxis(RoadForwardAxis, false);
		MeshComp->SetStartScale(FVector2D(RoadWidthScale, RoadThicknessScale), false);
		MeshComp->SetEndScale(FVector2D(RoadWidthScale, RoadThicknessScale), false);

		if (RoadMaterialOverride)
		{
			MeshComp->SetMaterial(0, RoadMaterialOverride);
		}

		MeshComp->SetCollisionEnabled(bRoadCollision ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
		if (!bRoadCollision)
		{
			MeshComp->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
		}

		const FVector StartPos = PathSpline->GetLocationAtSplinePoint(PointIndex, ESplineCoordinateSpace::Local);
		const FVector StartTangent = PathSpline->GetTangentAtSplinePoint(PointIndex, ESplineCoordinateSpace::Local);
		const FVector EndPos = PathSpline->GetLocationAtSplinePoint(PointIndex + 1, ESplineCoordinateSpace::Local);
		const FVector EndTangent = PathSpline->GetTangentAtSplinePoint(PointIndex + 1, ESplineCoordinateSpace::Local);
		MeshComp->SetStartAndEnd(StartPos, StartTangent, EndPos, EndTangent, true);

		MeshComp->AttachToComponent(PathSpline, FAttachmentTransformRules::KeepRelativeTransform);
		MeshComp->RegisterComponent();
		RoadSplineMeshes.Add(MeshComp);
	}
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

