// Copyright Ark. Ark Log Player — editor/runtime path preview actor.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineMeshComponent.h"
#include "ArkPathPreviewActor.generated.h"

class USplineComponent;
class USplineMeshComponent;
class UProceduralMeshComponent;
class UStaticMesh;
class UMaterialInterface;

UENUM(BlueprintType)
enum class EArkPathFlattenZMode : uint8
{
	/** Use the Z value of the first accepted path point. */
	FirstPointZ UMETA(DisplayName = "First Point Z"),
	/** Use this preview actor's world Z. */
	ActorZ UMETA(DisplayName = "Actor Z"),
	/** Use a custom absolute world-space Z value (cm). */
	CustomZ UMETA(DisplayName = "Custom Z"),
};

UENUM(BlueprintType)
enum class EArkTopologyBaseZMode : uint8
{
	/** Use this preview actor's world Z as the undeformed ground baseline. */
	ActorZ UMETA(DisplayName = "Actor Z"),
	/** Use the minimum path Z as undeformed ground baseline. */
	PathMinZ UMETA(DisplayName = "Path Min Z"),
	/** Use a custom absolute world-space Z value (cm). */
	CustomZ UMETA(DisplayName = "Custom Z"),
};

UENUM(BlueprintType)
enum class EArkTopologyPerformanceMode : uint8
{
	/** Use all manual topology values exactly as entered. */
	Manual UMETA(DisplayName = "Manual"),
	/** Auto-balance quality and speed for larger scenes. */
	BalancedLargeScene UMETA(DisplayName = "Balanced Large Scene"),
	/** Favor speed over fidelity for very large scenes. */
	AggressiveLargeScene UMETA(DisplayName = "Aggressive Large Scene"),
};

/**
 * Place this actor in a level to preview a full vehicle path from a .jsonl file.
 * Rebuilds in editor when properties change (OnConstruction) and can also be
 * triggered manually via the RebuildPreview button.
 */
UCLASS(BlueprintType, Blueprintable)
class ARKLOGPLAYER_API AArkPathPreviewActor : public AActor
{
	GENERATED_BODY()

public:
	AArkPathPreviewActor();

	/** Absolute path to the .jsonl playback file. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview")
	FString FilePath;

	/** Vehicle id to extract from the log. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview")
	int32 VehicleId = 0;

	/** Minimum time spacing between points. <= 0 means use every sample. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview", meta = (ClampMin = "0.0"))
	float MinSampleStepSec = 0.1f;

	/** Global world-space offset applied to all preview points (cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview")
	FVector WorldOffset = FVector::ZeroVector;

	/** Draw spline debug in viewport independently of generated road mesh. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview")
	bool bShowSplineDebug = true;

	/** Flatten all preview points to a single Z plane. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview")
	bool bFlattenPathZ = false;

	/** How to choose Z when flattening the path. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview", meta = (EditCondition = "bFlattenPathZ"))
	EArkPathFlattenZMode FlattenZMode = EArkPathFlattenZMode::FirstPointZ;

	/** Absolute world-space Z used when FlattenZMode is CustomZ. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview", meta = (EditCondition = "bFlattenPathZ && FlattenZMode == EArkPathFlattenZMode::CustomZ"))
	float FlattenZValue = 0.0f;

	/** Rebuild automatically when actor is constructed/edited. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview")
	bool bAutoRebuild = true;

	/** If true, clears spline points when build fails or no data found. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview")
	bool bClearOnFailure = true;

	/** Hard cap to protect editor from huge point counts. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview", meta = (ClampMin = "100", UIMin = "100"))
	int32 MaxPoints = 200000;

	/** If true, generate spline mesh road segments along the path. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Road Mesh")
	bool bGenerateRoadMesh = false;

	/** Static mesh used per spline segment (should be authored along the ForwardAxis direction). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Road Mesh", meta = (EditCondition = "bGenerateRoadMesh"))
	TObjectPtr<UStaticMesh> RoadMesh = nullptr;

	/** Optional material override for generated spline mesh segments. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Road Mesh", meta = (EditCondition = "bGenerateRoadMesh"))
	TObjectPtr<UMaterialInterface> RoadMaterialOverride = nullptr;

	/** Width scale for spline mesh segments. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Road Mesh", meta = (EditCondition = "bGenerateRoadMesh", ClampMin = "0.001", UIMin = "0.001"))
	float RoadWidthScale = 1.0f;

	/** Thickness/secondary scale for spline mesh segments. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Road Mesh", meta = (EditCondition = "bGenerateRoadMesh", ClampMin = "0.001", UIMin = "0.001"))
	float RoadThicknessScale = 1.0f;

	/** Mesh forward axis used by spline mesh deformation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Road Mesh", meta = (EditCondition = "bGenerateRoadMesh"))
	TEnumAsByte<ESplineMeshAxis::Type> RoadForwardAxis = ESplineMeshAxis::X;

	/** Enable collision on generated road meshes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Road Mesh", meta = (EditCondition = "bGenerateRoadMesh"))
	bool bRoadCollision = false;

	/** If true, generate a deformed ground mesh around the path. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh")
	bool bGenerateTopologyMesh = false;

	/** Optional material override for the generated topology mesh. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh"))
	TObjectPtr<UMaterialInterface> TopologyMaterialOverride = nullptr;

	/** Performance preset that can auto-tune topology generation in large scenes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh"))
	EArkTopologyPerformanceMode TopologyPerformanceMode = EArkTopologyPerformanceMode::BalancedLargeScene;

	/** Road half-width used for full-strength deformation (cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "1.0", UIMin = "1.0"))
	float TopologyRoadHalfWidthCm = 250.0f;

	/** Additional blend distance beyond road half-width (cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "0.0", UIMin = "0.0"))
	float TopologyInfluenceWidthCm = 1500.0f;

	/** Falloff exponent: 1 = linear, >1 = sharper shoulder. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "0.1", UIMin = "0.1"))
	float TopologyFalloffExponent = 1.0f;

	/** If true, apply smoothstep before exponent for gentler transitions. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh"))
	bool bTopologyUseSmoothstepFalloff = true;

	/** Grid spacing for generated ground mesh (cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "10.0", UIMin = "10.0"))
	float TopologyGridCellSizeCm = 100.0f;

	/** Distance spacing for centerline samples used by topology deformation (cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "10.0", UIMin = "10.0"))
	float TopologyPathSampleDistanceCm = 100.0f;

	/** Spatial hash cell size for nearest-path lookup (cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "50.0", UIMin = "50.0"))
	float TopologySpatialCellSizeCm = 500.0f;

	/** Extra padding around path bounds for generated ground mesh (cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "0.0", UIMin = "0.0"))
	float TopologyBoundsPaddingCm = 1000.0f;

	/** Max vertices safety cap for generated topology mesh. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "1000", UIMin = "1000"))
	int32 TopologyMaxVertices = 300000;

	/** Baseline Z mode for undeformed ground mesh. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh"))
	EArkTopologyBaseZMode TopologyBaseZMode = EArkTopologyBaseZMode::PathMinZ;

	/** Absolute baseline Z used when TopologyBaseZMode is CustomZ. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh && TopologyBaseZMode == EArkTopologyBaseZMode::CustomZ"))
	float TopologyBaseZValue = 0.0f;

	/** Enable collision on generated topology mesh. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh"))
	bool bTopologyCollision = false;

	/** Optional post-deformation smoothing passes (keeps road core sharper). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "0", UIMin = "0"))
	int32 TopologySmoothingPasses = 1;

	/** Strength per smoothing pass (0..1). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Path Preview|Topology Mesh", meta = (EditCondition = "bGenerateTopologyMesh", ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float TopologySmoothingStrength = 0.35f;

	/** Rebuild preview spline from current settings. */
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Ark Path Preview")
	void RebuildPreview();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

private:
	bool BuildPoints(TArray<FVector>& OutPoints, FString& OutError) const;
	void ClearRoadMeshes();
	void RebuildRoadMeshes();
	void RebuildTopologyMesh(const TArray<FVector>& PathPoints);
	void ClearTopologyMesh();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ark Path Preview", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USplineComponent> PathSpline;

	UPROPERTY(Transient)
	TArray<TObjectPtr<USplineMeshComponent>> RoadSplineMeshes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ark Path Preview", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UProceduralMeshComponent> TopologyMesh;
};

