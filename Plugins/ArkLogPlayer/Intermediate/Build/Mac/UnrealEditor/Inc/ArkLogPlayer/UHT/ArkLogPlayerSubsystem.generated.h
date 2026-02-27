// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ArkLogPlayerSubsystem.h"

#ifdef ARKLOGPLAYER_ArkLogPlayerSubsystem_generated_h
#error "ArkLogPlayerSubsystem.generated.h already included, missing '#pragma once' in ArkLogPlayerSubsystem.h"
#endif
#define ARKLOGPLAYER_ArkLogPlayerSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FArkVehicleState;

// ********** Begin Delegate FOnArkLogLoaded *******************************************************
#define FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_11_DELEGATE \
ARKLOGPLAYER_API void FOnArkLogLoaded_DelegateWrapper(const FMulticastScriptDelegate& OnArkLogLoaded);


// ********** End Delegate FOnArkLogLoaded *********************************************************

// ********** Begin Delegate FOnArkPlaybackTick ****************************************************
#define FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_12_DELEGATE \
ARKLOGPLAYER_API void FOnArkPlaybackTick_DelegateWrapper(const FMulticastScriptDelegate& OnArkPlaybackTick, float TimeSeconds);


// ********** End Delegate FOnArkPlaybackTick ******************************************************

// ********** Begin Class UArkLogPlayerSubsystem ***************************************************
#define FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetVehiclePath); \
	DECLARE_FUNCTION(execGetInterpolatedVehicleState); \
	DECLARE_FUNCTION(execGetVehicleIds); \
	DECLARE_FUNCTION(execGetDurationSeconds); \
	DECLARE_FUNCTION(execSeekTo); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execPause); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execLoadLog);


ARKLOGPLAYER_API UClass* Z_Construct_UClass_UArkLogPlayerSubsystem_NoRegister();

#define FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUArkLogPlayerSubsystem(); \
	friend struct Z_Construct_UClass_UArkLogPlayerSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ARKLOGPLAYER_API UClass* Z_Construct_UClass_UArkLogPlayerSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UArkLogPlayerSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ArkLogPlayer"), Z_Construct_UClass_UArkLogPlayerSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UArkLogPlayerSubsystem)


#define FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UArkLogPlayerSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UArkLogPlayerSubsystem(UArkLogPlayerSubsystem&&) = delete; \
	UArkLogPlayerSubsystem(const UArkLogPlayerSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UArkLogPlayerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UArkLogPlayerSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UArkLogPlayerSubsystem) \
	NO_API virtual ~UArkLogPlayerSubsystem();


#define FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_17_PROLOG
#define FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_20_INCLASS_NO_PURE_DECLS \
	FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UArkLogPlayerSubsystem;

// ********** End Class UArkLogPlayerSubsystem *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
