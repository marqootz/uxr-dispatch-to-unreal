// Copyright Ark. Ark Log Player — editor/runtime path preview actor.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineMeshComponent.h"
#include "ArkPathPreviewActor.generated.h"

class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
class UMaterialInterface;

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

	/** Rebuild preview spline from current settings. */
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Ark Path Preview")
	void RebuildPreview();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

private:
	bool BuildPoints(TArray<FVector>& OutPoints, FString& OutError) const;
	void ClearRoadMeshes();
	void RebuildRoadMeshes();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ark Path Preview", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USplineComponent> PathSpline;

	UPROPERTY(Transient)
	TArray<TObjectPtr<USplineMeshComponent>> RoadSplineMeshes;
};

