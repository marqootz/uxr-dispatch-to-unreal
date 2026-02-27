// Copyright Ark. Ark Log Player — coordinate conversion (source → UE5).
// Do not change without flagging: robotics right-handed Z-up → UE5 left-handed Z-up.

#pragma once

#include "CoreMinimal.h"

namespace ArkCoordinates
{
	/** Scale factor: source meters → UE5 cm. */
	constexpr float MetersToCm = 100.0f;

	/** Convert translation: meters, right-handed Z-up → UE5 cm, left-handed Z-up. */
	inline FVector SourceToUnreal(const FVector& SourceMeters)
	{
		return FVector(
			SourceMeters.X * MetersToCm,
			-SourceMeters.Y * MetersToCm,
			SourceMeters.Z * MetersToCm
		);
	}

	/** Convert quaternion: Hamilton (x,y,z,w), right-handed -> left-handed reflection, then normalize. */
	inline FQuat SourceToUnreal(float Qx, float Qy, float Qz, float Qw)
	{
		// Rotation axis is a pseudovector under reflection: for mirror on Y, axis mapping is (-X, +Y, -Z).
		FQuat Q(-Qx, Qy, -Qz, Qw);
		Q.Normalize();
		return Q;
	}
}
