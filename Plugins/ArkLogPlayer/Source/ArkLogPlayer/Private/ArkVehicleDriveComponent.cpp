// Copyright Ark. Ark Log Player — drive component implementation.

#include "ArkVehicleDriveComponent.h"
#include "ArkLogPlayerSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Actor.h"

UArkVehicleDriveComponent::UArkVehicleDriveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UArkVehicleDriveComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UArkVehicleDriveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Owner = GetOwner();
	if (!Owner)
	{
		bHasValidState = false;
		return;
	}

	UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	UArkLogPlayerSubsystem* Subsystem = GI ? GI->GetSubsystem<UArkLogPlayerSubsystem>() : nullptr;
	if (!Subsystem)
	{
		bHasValidState = false;
		return;
	}

	FArkVehicleState State;
	if (!Subsystem->GetInterpolatedVehicleState(VehicleId, State))
	{
		bHasValidState = false;
		return;
	}

	LastState = State;
	bHasValidState = true;
	Owner->SetActorLocationAndRotation(State.Position, State.Rotation);
}
