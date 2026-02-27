// Copyright Ark. Ark Log Player — UGameInstanceSubsystem: data + playback clock.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Containers/Ticker.h"
#include "ArkTypes.h"
#include "ArkLogPlayerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnArkLogLoaded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnArkPlaybackTick, float, TimeSeconds);

/**
 * Owns loaded log frames and playback state. Exposes load/play/seek and interpolated vehicle state.
 */
UCLASS()
class ARKLOGPLAYER_API UArkLogPlayerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Load a .jsonl file. Returns false and sets OutError on failure. */
	UFUNCTION(BlueprintCallable, Category = "Ark Log Player")
	bool LoadLog(FString FilePath, FString& OutError);

	UFUNCTION(BlueprintCallable, Category = "Ark Log Player")
	void Play();

	UFUNCTION(BlueprintCallable, Category = "Ark Log Player")
	void Pause();

	UFUNCTION(BlueprintCallable, Category = "Ark Log Player")
	void Stop();

	UFUNCTION(BlueprintCallable, Category = "Ark Log Player")
	void SeekTo(float TimeSeconds);

	UFUNCTION(BlueprintPure, Category = "Ark Log Player")
	float GetDurationSeconds() const;

	UFUNCTION(BlueprintPure, Category = "Ark Log Player")
	TArray<int32> GetVehicleIds() const;

	/** Get interpolated state for VehicleId at current playback time. Returns false if no data. */
	UFUNCTION(BlueprintCallable, Category = "Ark Log Player")
	bool GetInterpolatedVehicleState(int32 VehicleId, FArkVehicleState& OutState) const;

	/**
	 * Get sampled path points for a vehicle from loaded frames.
	 * MinSampleStepSec <= 0 returns every frame sample for that vehicle.
	 */
	UFUNCTION(BlueprintCallable, Category = "Ark Log Player")
	bool GetVehiclePath(int32 VehicleId, TArray<FVector>& OutPoints, float MinSampleStepSec = 0.0f) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Log Player")
	float PlaybackSpeed = 1.0f;

	/** Global world-space offset (cm) applied to all reported vehicle positions and paths. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Log Player")
	FVector PlaybackWorldOffset = FVector::ZeroVector;

	/** Local rotation offset applied after log rotation (useful for mesh forward-axis differences). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ark Log Player")
	FRotator PlaybackRotationOffset = FRotator::ZeroRotator;

	UPROPERTY(BlueprintReadOnly, Category = "Ark Log Player")
	float PlaybackTimeSec = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ark Log Player")
	bool bIsPlaying = false;

	UPROPERTY(BlueprintAssignable, Category = "Ark Log Player")
	FOnArkLogLoaded OnLogLoaded;

	UPROPERTY(BlueprintAssignable, Category = "Ark Log Player")
	FOnArkPlaybackTick OnPlaybackTick;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Called from game thread each tick when bIsPlaying. */
	void Tick(float DeltaSeconds);

private:
	bool TickTicker(float DeltaTime);

	TArray<FArkFrame> Frames_;
	TMap<int32, TArray<int32>> VehicleFrameIndex_;
	int64 TimeNsMin_ = 0;
	int64 TimeNsMax_ = 0;
	double PlaybackTimeNs_ = 0.0;
	FTSTicker::FDelegateHandle TickerHandle_;
};
