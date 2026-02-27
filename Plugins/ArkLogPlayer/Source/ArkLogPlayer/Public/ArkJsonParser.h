// Copyright Ark. Ark Log Player — parse .jsonl → TArray<FArkFrame>.

#pragma once

#include "CoreMinimal.h"
#include "ArkTypes.h"

/**
 * Parses a logtool JSON-lines export into frames.
 * Timestamp (in order): time.local_time (VehicleStatus), _ark_metadata.logged_timestamp (with --include-message-metadata), stamp.local_time (other channels).
 * Vehicle body: statuses[] with id, state.pose.translation, state.pose.rotation.
 */
class ARKLOGPLAYER_API FArkJsonParser
{
public:
	/** Parse entire file; returns false and sets OutError on failure. */
	static bool ParseFile(const FString& FilePath, TArray<FArkFrame>& OutFrames, FString& OutError);

	/** Parse a single line; returns true if line produced a valid frame (optional). */
	static bool ParseLine(const FString& Line, FArkFrame& OutFrame, FString& OutError);
};
