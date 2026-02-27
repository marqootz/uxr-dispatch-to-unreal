// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArkLogPlayerSubsystem.h"
#include "ArkTypes.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeArkLogPlayerSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ARKLOGPLAYER_API UClass* Z_Construct_UClass_UArkLogPlayerSubsystem();
ARKLOGPLAYER_API UClass* Z_Construct_UClass_UArkLogPlayerSubsystem_NoRegister();
ARKLOGPLAYER_API UFunction* Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature();
ARKLOGPLAYER_API UFunction* Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature();
ARKLOGPLAYER_API UScriptStruct* Z_Construct_UScriptStruct_FArkVehicleState();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_ArkLogPlayer();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnArkLogLoaded *******************************************************
struct Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ArkLogPlayer, nullptr, "OnArkLogLoaded__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnArkLogLoaded_DelegateWrapper(const FMulticastScriptDelegate& OnArkLogLoaded)
{
	OnArkLogLoaded.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnArkLogLoaded *********************************************************

// ********** Begin Delegate FOnArkPlaybackTick ****************************************************
struct Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics
{
	struct _Script_ArkLogPlayer_eventOnArkPlaybackTick_Parms
	{
		float TimeSeconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::NewProp_TimeSeconds = { "TimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ArkLogPlayer_eventOnArkPlaybackTick_Parms, TimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::NewProp_TimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ArkLogPlayer, nullptr, "OnArkPlaybackTick__DelegateSignature", Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::_Script_ArkLogPlayer_eventOnArkPlaybackTick_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::_Script_ArkLogPlayer_eventOnArkPlaybackTick_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnArkPlaybackTick_DelegateWrapper(const FMulticastScriptDelegate& OnArkPlaybackTick, float TimeSeconds)
{
	struct _Script_ArkLogPlayer_eventOnArkPlaybackTick_Parms
	{
		float TimeSeconds;
	};
	_Script_ArkLogPlayer_eventOnArkPlaybackTick_Parms Parms;
	Parms.TimeSeconds=TimeSeconds;
	OnArkPlaybackTick.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnArkPlaybackTick ******************************************************

// ********** Begin Class UArkLogPlayerSubsystem Function GetDurationSeconds ***********************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics
{
	struct ArkLogPlayerSubsystem_eventGetDurationSeconds_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventGetDurationSeconds_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "GetDurationSeconds", Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::PropPointers), sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::ArkLogPlayerSubsystem_eventGetDurationSeconds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::ArkLogPlayerSubsystem_eventGetDurationSeconds_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execGetDurationSeconds)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetDurationSeconds();
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function GetDurationSeconds *************************

// ********** Begin Class UArkLogPlayerSubsystem Function GetInterpolatedVehicleState **************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics
{
	struct ArkLogPlayerSubsystem_eventGetInterpolatedVehicleState_Parms
	{
		int32 VehicleId;
		FArkVehicleState OutState;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get interpolated state for VehicleId at current playback time. Returns false if no data. */" },
#endif
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get interpolated state for VehicleId at current playback time. Returns false if no data." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_VehicleId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutState;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_VehicleId = { "VehicleId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventGetInterpolatedVehicleState_Parms, VehicleId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_OutState = { "OutState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventGetInterpolatedVehicleState_Parms, OutState), Z_Construct_UScriptStruct_FArkVehicleState, METADATA_PARAMS(0, nullptr) }; // 3562814615
void Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ArkLogPlayerSubsystem_eventGetInterpolatedVehicleState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ArkLogPlayerSubsystem_eventGetInterpolatedVehicleState_Parms), &Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_VehicleId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_OutState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "GetInterpolatedVehicleState", Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::ArkLogPlayerSubsystem_eventGetInterpolatedVehicleState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::ArkLogPlayerSubsystem_eventGetInterpolatedVehicleState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execGetInterpolatedVehicleState)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_VehicleId);
	P_GET_STRUCT_REF(FArkVehicleState,Z_Param_Out_OutState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetInterpolatedVehicleState(Z_Param_VehicleId,Z_Param_Out_OutState);
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function GetInterpolatedVehicleState ****************

// ********** Begin Class UArkLogPlayerSubsystem Function GetVehicleIds ****************************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics
{
	struct ArkLogPlayerSubsystem_eventGetVehicleIds_Parms
	{
		TArray<int32> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventGetVehicleIds_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "GetVehicleIds", Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::PropPointers), sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::ArkLogPlayerSubsystem_eventGetVehicleIds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::ArkLogPlayerSubsystem_eventGetVehicleIds_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execGetVehicleIds)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<int32>*)Z_Param__Result=P_THIS->GetVehicleIds();
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function GetVehicleIds ******************************

// ********** Begin Class UArkLogPlayerSubsystem Function GetVehiclePath ***************************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics
{
	struct ArkLogPlayerSubsystem_eventGetVehiclePath_Parms
	{
		int32 VehicleId;
		TArray<FVector> OutPoints;
		float MinSampleStepSec;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get sampled path points for a vehicle from loaded frames.\n\x09 * MinSampleStepSec <= 0 returns every frame sample for that vehicle.\n\x09 */" },
#endif
		{ "CPP_Default_MinSampleStepSec", "0.000000" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get sampled path points for a vehicle from loaded frames.\nMinSampleStepSec <= 0 returns every frame sample for that vehicle." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_VehicleId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutPoints;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinSampleStepSec;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_VehicleId = { "VehicleId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventGetVehiclePath_Parms, VehicleId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_OutPoints_Inner = { "OutPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_OutPoints = { "OutPoints", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventGetVehiclePath_Parms, OutPoints), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_MinSampleStepSec = { "MinSampleStepSec", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventGetVehiclePath_Parms, MinSampleStepSec), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ArkLogPlayerSubsystem_eventGetVehiclePath_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ArkLogPlayerSubsystem_eventGetVehiclePath_Parms), &Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_VehicleId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_OutPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_OutPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_MinSampleStepSec,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "GetVehiclePath", Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::ArkLogPlayerSubsystem_eventGetVehiclePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::ArkLogPlayerSubsystem_eventGetVehiclePath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execGetVehiclePath)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_VehicleId);
	P_GET_TARRAY_REF(FVector,Z_Param_Out_OutPoints);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MinSampleStepSec);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetVehiclePath(Z_Param_VehicleId,Z_Param_Out_OutPoints,Z_Param_MinSampleStepSec);
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function GetVehiclePath *****************************

// ********** Begin Class UArkLogPlayerSubsystem Function LoadLog **********************************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics
{
	struct ArkLogPlayerSubsystem_eventLoadLog_Parms
	{
		FString FilePath;
		FString OutError;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Load a .jsonl file. Returns false and sets OutError on failure. */" },
#endif
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load a .jsonl file. Returns false and sets OutError on failure." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutError;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventLoadLog_Parms, FilePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_OutError = { "OutError", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventLoadLog_Parms, OutError), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ArkLogPlayerSubsystem_eventLoadLog_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ArkLogPlayerSubsystem_eventLoadLog_Parms), &Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_OutError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "LoadLog", Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::PropPointers), sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::ArkLogPlayerSubsystem_eventLoadLog_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::ArkLogPlayerSubsystem_eventLoadLog_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execLoadLog)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutError);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LoadLog(Z_Param_FilePath,Z_Param_Out_OutError);
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function LoadLog ************************************

// ********** Begin Class UArkLogPlayerSubsystem Function Pause ************************************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_Pause_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_Pause_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "Pause", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_Pause_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_Pause_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_Pause()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_Pause_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execPause)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Pause();
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function Pause **************************************

// ********** Begin Class UArkLogPlayerSubsystem Function Play *************************************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_Play_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_Play_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "Play", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_Play_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_Play_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_Play()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_Play_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execPlay)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Play();
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function Play ***************************************

// ********** Begin Class UArkLogPlayerSubsystem Function SeekTo ***********************************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics
{
	struct ArkLogPlayerSubsystem_eventSeekTo_Parms
	{
		float TimeSeconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::NewProp_TimeSeconds = { "TimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ArkLogPlayerSubsystem_eventSeekTo_Parms, TimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::NewProp_TimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "SeekTo", Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::ArkLogPlayerSubsystem_eventSeekTo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::ArkLogPlayerSubsystem_eventSeekTo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execSeekTo)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_TimeSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SeekTo(Z_Param_TimeSeconds);
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function SeekTo *************************************

// ********** Begin Class UArkLogPlayerSubsystem Function Stop *************************************
struct Z_Construct_UFunction_UArkLogPlayerSubsystem_Stop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UArkLogPlayerSubsystem_Stop_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UArkLogPlayerSubsystem, nullptr, "Stop", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UArkLogPlayerSubsystem_Stop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UArkLogPlayerSubsystem_Stop_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UArkLogPlayerSubsystem_Stop()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UArkLogPlayerSubsystem_Stop_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UArkLogPlayerSubsystem::execStop)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Stop();
	P_NATIVE_END;
}
// ********** End Class UArkLogPlayerSubsystem Function Stop ***************************************

// ********** Begin Class UArkLogPlayerSubsystem ***************************************************
void UArkLogPlayerSubsystem::StaticRegisterNativesUArkLogPlayerSubsystem()
{
	UClass* Class = UArkLogPlayerSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetDurationSeconds", &UArkLogPlayerSubsystem::execGetDurationSeconds },
		{ "GetInterpolatedVehicleState", &UArkLogPlayerSubsystem::execGetInterpolatedVehicleState },
		{ "GetVehicleIds", &UArkLogPlayerSubsystem::execGetVehicleIds },
		{ "GetVehiclePath", &UArkLogPlayerSubsystem::execGetVehiclePath },
		{ "LoadLog", &UArkLogPlayerSubsystem::execLoadLog },
		{ "Pause", &UArkLogPlayerSubsystem::execPause },
		{ "Play", &UArkLogPlayerSubsystem::execPlay },
		{ "SeekTo", &UArkLogPlayerSubsystem::execSeekTo },
		{ "Stop", &UArkLogPlayerSubsystem::execStop },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UArkLogPlayerSubsystem;
UClass* UArkLogPlayerSubsystem::GetPrivateStaticClass()
{
	using TClass = UArkLogPlayerSubsystem;
	if (!Z_Registration_Info_UClass_UArkLogPlayerSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ArkLogPlayerSubsystem"),
			Z_Registration_Info_UClass_UArkLogPlayerSubsystem.InnerSingleton,
			StaticRegisterNativesUArkLogPlayerSubsystem,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UArkLogPlayerSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UArkLogPlayerSubsystem_NoRegister()
{
	return UArkLogPlayerSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UArkLogPlayerSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Owns loaded log frames and playback state. Exposes load/play/seek and interpolated vehicle state.\n */" },
#endif
		{ "IncludePath", "ArkLogPlayerSubsystem.h" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owns loaded log frames and playback state. Exposes load/play/seek and interpolated vehicle state." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaybackSpeed_MetaData[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaybackWorldOffset_MetaData[] = {
		{ "Category", "Ark Log Player" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global world-space offset (cm) applied to all reported vehicle positions and paths. */" },
#endif
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global world-space offset (cm) applied to all reported vehicle positions and paths." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaybackRotationOffset_MetaData[] = {
		{ "Category", "Ark Log Player" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local rotation offset applied after log rotation (useful for mesh forward-axis differences). */" },
#endif
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local rotation offset applied after log rotation (useful for mesh forward-axis differences)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaybackTimeSec_MetaData[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlaying_MetaData[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLogLoaded_MetaData[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlaybackTick_MetaData[] = {
		{ "Category", "Ark Log Player" },
		{ "ModuleRelativePath", "Public/ArkLogPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaybackWorldOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaybackRotationOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackTimeSec;
	static void NewProp_bIsPlaying_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlaying;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLogLoaded;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlaybackTick;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_GetDurationSeconds, "GetDurationSeconds" }, // 2798303018
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_GetInterpolatedVehicleState, "GetInterpolatedVehicleState" }, // 2760470039
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehicleIds, "GetVehicleIds" }, // 188981476
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_GetVehiclePath, "GetVehiclePath" }, // 320094343
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_LoadLog, "LoadLog" }, // 3285519473
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_Pause, "Pause" }, // 1084795010
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_Play, "Play" }, // 1454938366
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_SeekTo, "SeekTo" }, // 2434375900
		{ &Z_Construct_UFunction_UArkLogPlayerSubsystem_Stop, "Stop" }, // 2502493124
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UArkLogPlayerSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackSpeed = { "PlaybackSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkLogPlayerSubsystem, PlaybackSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaybackSpeed_MetaData), NewProp_PlaybackSpeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackWorldOffset = { "PlaybackWorldOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkLogPlayerSubsystem, PlaybackWorldOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaybackWorldOffset_MetaData), NewProp_PlaybackWorldOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackRotationOffset = { "PlaybackRotationOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkLogPlayerSubsystem, PlaybackRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaybackRotationOffset_MetaData), NewProp_PlaybackRotationOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackTimeSec = { "PlaybackTimeSec", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkLogPlayerSubsystem, PlaybackTimeSec), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaybackTimeSec_MetaData), NewProp_PlaybackTimeSec_MetaData) };
void Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_bIsPlaying_SetBit(void* Obj)
{
	((UArkLogPlayerSubsystem*)Obj)->bIsPlaying = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_bIsPlaying = { "bIsPlaying", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UArkLogPlayerSubsystem), &Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_bIsPlaying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlaying_MetaData), NewProp_bIsPlaying_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_OnLogLoaded = { "OnLogLoaded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkLogPlayerSubsystem, OnLogLoaded), Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLogLoaded_MetaData), NewProp_OnLogLoaded_MetaData) }; // 2703383798
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_OnPlaybackTick = { "OnPlaybackTick", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkLogPlayerSubsystem, OnPlaybackTick), Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlaybackTick_MetaData), NewProp_OnPlaybackTick_MetaData) }; // 1493428931
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackWorldOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackRotationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_PlaybackTimeSec,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_bIsPlaying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_OnLogLoaded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::NewProp_OnPlaybackTick,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ArkLogPlayer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::ClassParams = {
	&UArkLogPlayerSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UArkLogPlayerSubsystem()
{
	if (!Z_Registration_Info_UClass_UArkLogPlayerSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UArkLogPlayerSubsystem.OuterSingleton, Z_Construct_UClass_UArkLogPlayerSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UArkLogPlayerSubsystem.OuterSingleton;
}
UArkLogPlayerSubsystem::UArkLogPlayerSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UArkLogPlayerSubsystem);
UArkLogPlayerSubsystem::~UArkLogPlayerSubsystem() {}
// ********** End Class UArkLogPlayerSubsystem *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h__Script_ArkLogPlayer_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UArkLogPlayerSubsystem, UArkLogPlayerSubsystem::StaticClass, TEXT("UArkLogPlayerSubsystem"), &Z_Registration_Info_UClass_UArkLogPlayerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UArkLogPlayerSubsystem), 3052761889U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h__Script_ArkLogPlayer_410084420(TEXT("/Script/ArkLogPlayer"),
	Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h__Script_ArkLogPlayer_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkLogPlayerSubsystem_h__Script_ArkLogPlayer_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
