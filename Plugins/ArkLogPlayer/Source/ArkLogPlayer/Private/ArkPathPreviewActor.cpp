// Copyright Ark. Ark Log Player — editor/runtime path preview actor.

#include "ArkPathPreviewActor.h"

#include "ArkJsonParser.h"
#include "ArkTypes.h"
#include "ProceduralMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "KismetProceduralMeshLibrary.h"

AArkPathPreviewActor::AArkPathPreviewActor()
{
	PrimaryActorTick.bCanEverTick = false;

	PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("PathSpline"));
	SetRootComponent(PathSpline);
	PathSpline->SetMobility(EComponentMobility::Movable);
	PathSpline->bDrawDebug = bShowSplineDebug;

	TopologyMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("TopologyMesh"));
	TopologyMesh->SetupAttachment(PathSpline);
	TopologyMesh->SetMobility(EComponentMobility::Movable);
	TopologyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
			ClearTopologyMesh();
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
	RebuildTopologyMesh(Points);

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

void AArkPathPreviewActor::ClearTopologyMesh()
{
	if (!TopologyMesh)
	{
		return;
	}
	TopologyMesh->ClearAllMeshSections();
}

void AArkPathPreviewActor::RebuildTopologyMesh(const TArray<FVector>& PathPoints)
{
	ClearTopologyMesh();

	if (!bGenerateTopologyMesh || !TopologyMesh || !PathSpline || PathPoints.Num() < 2)
	{
		return;
	}

	// Start from manual settings, then optionally auto-tune for large scenes.
	float EffectiveGridCell = TopologyGridCellSizeCm;
	float EffectivePathSampleDistance = TopologyPathSampleDistanceCm;
	float EffectiveSpatialCellSize = TopologySpatialCellSizeCm;
	bool bEffectiveUseSmoothstep = bTopologyUseSmoothstepFalloff;
	int32 EffectiveSmoothingPasses = TopologySmoothingPasses;
	float EffectiveSmoothingStrength = TopologySmoothingStrength;
	float EffectiveFalloffExponent = TopologyFalloffExponent;

	float MinX = TNumericLimits<float>::Max();
	float MinY = TNumericLimits<float>::Max();
	float MaxX = TNumericLimits<float>::Lowest();
	float MaxY = TNumericLimits<float>::Lowest();
	float PathMinZ = TNumericLimits<float>::Max();
	for (const FVector& P : PathPoints)
	{
		MinX = FMath::Min(MinX, P.X);
		MinY = FMath::Min(MinY, P.Y);
		MaxX = FMath::Max(MaxX, P.X);
		MaxY = FMath::Max(MaxY, P.Y);
		PathMinZ = FMath::Min(PathMinZ, P.Z);
	}

	const float InfluenceRadius = TopologyRoadHalfWidthCm + TopologyInfluenceWidthCm;
	const float PathSpanX = MaxX - MinX;
	const float PathSpanY = MaxY - MinY;
	const float MaxPathSpan = FMath::Max(PathSpanX, PathSpanY);

	if (TopologyPerformanceMode == EArkTopologyPerformanceMode::BalancedLargeScene)
	{
		EffectivePathSampleDistance = FMath::Max(EffectivePathSampleDistance, FMath::Max(75.0f, InfluenceRadius * 0.30f));
		EffectiveSpatialCellSize = FMath::Max(EffectiveSpatialCellSize, FMath::Max(350.0f, InfluenceRadius * 0.65f));
		if (MaxPathSpan > 40000.0f) { EffectiveGridCell = FMath::Max(EffectiveGridCell, 140.0f); }   // 400m+
		if (MaxPathSpan > 100000.0f) { EffectiveGridCell = FMath::Max(EffectiveGridCell, 220.0f); }  // 1km+
		EffectiveFalloffExponent = FMath::Min(EffectiveFalloffExponent, 1.0f);
		bEffectiveUseSmoothstep = true;
		EffectiveSmoothingPasses = FMath::Max(EffectiveSmoothingPasses, 1);
		EffectiveSmoothingStrength = FMath::Max(EffectiveSmoothingStrength, 0.30f);
	}
	else if (TopologyPerformanceMode == EArkTopologyPerformanceMode::AggressiveLargeScene)
	{
		EffectivePathSampleDistance = FMath::Max(EffectivePathSampleDistance, FMath::Max(120.0f, InfluenceRadius * 0.45f));
		EffectiveSpatialCellSize = FMath::Max(EffectiveSpatialCellSize, FMath::Max(500.0f, InfluenceRadius * 0.90f));
		if (MaxPathSpan > 25000.0f) { EffectiveGridCell = FMath::Max(EffectiveGridCell, 180.0f); }   // 250m+
		if (MaxPathSpan > 75000.0f) { EffectiveGridCell = FMath::Max(EffectiveGridCell, 280.0f); }   // 750m+
		if (MaxPathSpan > 150000.0f) { EffectiveGridCell = FMath::Max(EffectiveGridCell, 400.0f); }  // 1.5km+
		EffectiveFalloffExponent = FMath::Min(EffectiveFalloffExponent, 0.9f);
		bEffectiveUseSmoothstep = true;
		EffectiveSmoothingPasses = FMath::Max(EffectiveSmoothingPasses, 1);
		EffectiveSmoothingStrength = FMath::Max(EffectiveSmoothingStrength, 0.40f);
	}

	const float Padding = FMath::Max(TopologyBoundsPaddingCm, InfluenceRadius);
	MinX -= Padding;
	MinY -= Padding;
	MaxX += Padding;
	MaxY += Padding;

	// Rebuild path samples using effective sample distance.
	TArray<FVector> PathSamples;
	const float SplineLength = PathSpline->GetSplineLength();
	const float PathSampleStep = FMath::Max(10.0f, EffectivePathSampleDistance);
	const int32 NumPathSamples = FMath::Max(2, FMath::CeilToInt(SplineLength / PathSampleStep) + 1);
	PathSamples.Reserve(NumPathSamples);
	for (int32 i = 0; i < NumPathSamples; ++i)
	{
		const float Dist = (static_cast<float>(i) / static_cast<float>(NumPathSamples - 1)) * SplineLength;
		PathSamples.Add(PathSpline->GetLocationAtDistanceAlongSpline(Dist, ESplineCoordinateSpace::World));
	}

	float Cell = FMath::Max(10.0f, EffectiveGridCell);
	int32 NumX = FMath::FloorToInt((MaxX - MinX) / Cell) + 1;
	int32 NumY = FMath::FloorToInt((MaxY - MinY) / Cell) + 1;
	int64 VertexCount = static_cast<int64>(NumX) * static_cast<int64>(NumY);
	if (VertexCount > TopologyMaxVertices)
	{
		const double Scale = FMath::Sqrt(static_cast<double>(VertexCount) / static_cast<double>(TopologyMaxVertices));
		Cell = static_cast<float>(Cell * Scale);
		NumX = FMath::FloorToInt((MaxX - MinX) / Cell) + 1;
		NumY = FMath::FloorToInt((MaxY - MinY) / Cell) + 1;
		VertexCount = static_cast<int64>(NumX) * static_cast<int64>(NumY);
	}
	if (NumX < 2 || NumY < 2 || VertexCount <= 0 || VertexCount > TopologyMaxVertices)
	{
		UE_LOG(LogTemp, Warning, TEXT("ArkPathPreviewActor '%s' topology mesh skipped. Invalid grid size (%d x %d)."), *GetName(), NumX, NumY);
		return;
	}

	// Build spatial hash for nearest-path lookup in large scenes.
	const float HashCellSize = FMath::Max(50.0f, EffectiveSpatialCellSize);
	auto ToCell = [HashCellSize](float X, float Y) -> FIntPoint
	{
		return FIntPoint(
			FMath::FloorToInt(X / HashCellSize),
			FMath::FloorToInt(Y / HashCellSize)
		);
	};

	TMap<FIntPoint, TArray<int32>> SampleCells;
	SampleCells.Reserve(PathSamples.Num() * 2);
	for (int32 SampleIdx = 0; SampleIdx < PathSamples.Num(); ++SampleIdx)
	{
		const FIntPoint CellKey = ToCell(PathSamples[SampleIdx].X, PathSamples[SampleIdx].Y);
		SampleCells.FindOrAdd(CellKey).Add(SampleIdx);
	}
	const int32 SearchCellRadius = FMath::Max(1, FMath::CeilToInt(InfluenceRadius / HashCellSize));

	float BaseZ = GetActorLocation().Z;
	switch (TopologyBaseZMode)
	{
	case EArkTopologyBaseZMode::PathMinZ:
		BaseZ = PathMinZ;
		break;
	case EArkTopologyBaseZMode::CustomZ:
		BaseZ = TopologyBaseZValue;
		break;
	case EArkTopologyBaseZMode::ActorZ:
	default:
		BaseZ = GetActorLocation().Z;
		break;
	}

	const FTransform ActorTransform = GetActorTransform();
	TArray<FVector> Vertices;
	TArray<FVector2D> UV0;
	TArray<float> DeformWeights;
	TArray<int32> Triangles;
	Vertices.Reserve(static_cast<int32>(VertexCount));
	UV0.Reserve(static_cast<int32>(VertexCount));
	DeformWeights.Reserve(static_cast<int32>(VertexCount));
	Triangles.Reserve((NumX - 1) * (NumY - 1) * 6);

	const float DenX = FMath::Max(1.0f, static_cast<float>(NumX - 1));
	const float DenY = FMath::Max(1.0f, static_cast<float>(NumY - 1));

	for (int32 Y = 0; Y < NumY; ++Y)
	{
		for (int32 X = 0; X < NumX; ++X)
		{
			const float WX = MinX + static_cast<float>(X) * Cell;
			const float WY = MinY + static_cast<float>(Y) * Cell;

			float NearestDistSq = TNumericLimits<float>::Max();
			float NearestPathZ = BaseZ;
			const FIntPoint CenterCell = ToCell(WX, WY);
			for (int32 DY = -SearchCellRadius; DY <= SearchCellRadius; ++DY)
			{
				for (int32 DX = -SearchCellRadius; DX <= SearchCellRadius; ++DX)
				{
					const FIntPoint CellKey(CenterCell.X + DX, CenterCell.Y + DY);
					const TArray<int32>* CellSamples = SampleCells.Find(CellKey);
					if (!CellSamples)
					{
						continue;
					}
					for (const int32 SampleIdx : *CellSamples)
					{
						const FVector& P = PathSamples[SampleIdx];
						const float SX = WX - P.X;
						const float SY = WY - P.Y;
						const float DistSq = SX * SX + SY * SY;
						if (DistSq < NearestDistSq)
						{
							NearestDistSq = DistSq;
							NearestPathZ = P.Z;
						}
					}
				}
			}

			const float Dist = FMath::Sqrt(NearestDistSq);
			float Weight = 0.0f;
			if (Dist <= TopologyRoadHalfWidthCm)
			{
				Weight = 1.0f;
			}
			else if (Dist <= InfluenceRadius && TopologyInfluenceWidthCm > KINDA_SMALL_NUMBER)
			{
				const float T = (Dist - TopologyRoadHalfWidthCm) / TopologyInfluenceWidthCm;
				float Falloff = FMath::Clamp(1.0f - T, 0.0f, 1.0f);
				if (bEffectiveUseSmoothstep)
				{
					Falloff = Falloff * Falloff * (3.0f - 2.0f * Falloff); // smoothstep
				}
				Weight = FMath::Pow(Falloff, EffectiveFalloffExponent);
			}

			const float WZ = FMath::Lerp(BaseZ, NearestPathZ, Weight);
			const FVector WorldPos(WX, WY, WZ);
			Vertices.Add(ActorTransform.InverseTransformPosition(WorldPos));
			UV0.Add(FVector2D(static_cast<float>(X) / DenX, static_cast<float>(Y) / DenY));
			DeformWeights.Add(Weight);
		}
	}

	// Optional smoothing pass: preserves road core, smooths broader ground deformation.
	for (int32 Pass = 0; Pass < EffectiveSmoothingPasses; ++Pass)
	{
		if (EffectiveSmoothingStrength <= KINDA_SMALL_NUMBER)
		{
			break;
		}
		TArray<float> PrevZ;
		PrevZ.SetNumUninitialized(Vertices.Num());
		for (int32 I = 0; I < Vertices.Num(); ++I)
		{
			PrevZ[I] = Vertices[I].Z;
		}

		for (int32 Y = 0; Y < NumY; ++Y)
		{
			for (int32 X = 0; X < NumX; ++X)
			{
				const int32 I = Y * NumX + X;
				const float Preserve = FMath::Clamp(DeformWeights[I], 0.0f, 1.0f);
				const float Blend = EffectiveSmoothingStrength * (1.0f - Preserve);
				if (Blend <= KINDA_SMALL_NUMBER)
				{
					continue;
				}

				float Sum = PrevZ[I];
				float Count = 1.0f;
				if (X > 0) { Sum += PrevZ[I - 1]; Count += 1.0f; }
				if (X < NumX - 1) { Sum += PrevZ[I + 1]; Count += 1.0f; }
				if (Y > 0) { Sum += PrevZ[I - NumX]; Count += 1.0f; }
				if (Y < NumY - 1) { Sum += PrevZ[I + NumX]; Count += 1.0f; }

				const float Avg = Sum / Count;
				Vertices[I].Z = FMath::Lerp(PrevZ[I], Avg, Blend);
			}
		}
	}

	for (int32 Y = 0; Y < NumY - 1; ++Y)
	{
		for (int32 X = 0; X < NumX - 1; ++X)
		{
			const int32 I0 = Y * NumX + X;
			const int32 I1 = I0 + 1;
			const int32 I2 = I0 + NumX;
			const int32 I3 = I2 + 1;

			Triangles.Add(I0);
			Triangles.Add(I2);
			Triangles.Add(I1);

			Triangles.Add(I1);
			Triangles.Add(I2);
			Triangles.Add(I3);
		}
	}

	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UV0, Normals, Tangents);
	TArray<FLinearColor> VertexColors;
	TopologyMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, bTopologyCollision, false);
	TopologyMesh->SetCollisionEnabled(bTopologyCollision ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	if (!bTopologyCollision)
	{
		TopologyMesh->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	}
	if (TopologyMaterialOverride)
	{
		TopologyMesh->SetMaterial(0, TopologyMaterialOverride);
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
	const float FlattenPlaneZFromActor = GetActorLocation().Z;
	bool bHasFlattenPlaneFromFirstPoint = false;
	float FlattenPlaneZ = 0.0f;

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
				FVector Point = V.Position + WorldOffset;

				if (bFlattenPathZ)
				{
					switch (FlattenZMode)
					{
					case EArkPathFlattenZMode::ActorZ:
						FlattenPlaneZ = FlattenPlaneZFromActor;
						Point.Z = FlattenPlaneZ;
						break;
					case EArkPathFlattenZMode::CustomZ:
						FlattenPlaneZ = FlattenZValue;
						Point.Z = FlattenPlaneZ;
						break;
					case EArkPathFlattenZMode::FirstPointZ:
					default:
						if (!bHasFlattenPlaneFromFirstPoint)
						{
							FlattenPlaneZ = Point.Z;
							bHasFlattenPlaneFromFirstPoint = true;
						}
						Point.Z = FlattenPlaneZ;
						break;
					}
				}

				OutPoints.Add(Point);
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

