// Copyright Ark. Ark Log Player — core data types.

#pragma once

#include "CoreMinimal.h"
#include "ArkTypes.generated.h"

/** Single vehicle state at a point in time (UE5 space: cm, left-handed). */
USTRUCT(BlueprintType)
struct ARKLOGPLAYER_API FArkVehicleState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark")
	int32 VehicleId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark")
	FVector Position = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark")
	FQuat Rotation = FQuat::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark")
	int64 TimestampNs = 0;
};

/** One frame of telemetry: timestamp + all vehicle states for that frame. */
USTRUCT(BlueprintType)
struct ARKLOGPLAYER_API FArkFrame
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark")
	int64 TimestampNs = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark")
	TArray<FArkVehicleState> Vehicles;
};
