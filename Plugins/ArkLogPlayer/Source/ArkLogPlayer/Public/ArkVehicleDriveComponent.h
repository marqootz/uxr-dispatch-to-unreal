// Copyright Ark. Ark Log Player — UActorComponent: drives Actor transform from subsystem.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArkTypes.h"
#include "ArkVehicleDriveComponent.generated.h"

class UArkLogPlayerSubsystem;

/**
 * Attach to a vehicle Actor. Set VehicleId (Blueprint or at spawn); each tick
 * fetches interpolated state from the log player subsystem and sets the Actor's
 * location and rotation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ARKLOGPLAYER_API UArkVehicleDriveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UArkVehicleDriveComponent();

	/** Vehicle id matching the log's statuses[].id. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark")
	int32 VehicleId = 0;

	/** Last state applied (for debug). */
	UPROPERTY(BlueprintReadOnly, Category = "Ark")
	FArkVehicleState LastState;

	/** True when we have valid state from the subsystem this tick. */
	UPROPERTY(BlueprintReadOnly, Category = "Ark")
	bool bHasValidState = false;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
};
