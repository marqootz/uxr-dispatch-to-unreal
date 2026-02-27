// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArkTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeArkTypes() {}

// ********** Begin Cross Module References ********************************************************
ARKLOGPLAYER_API UScriptStruct* Z_Construct_UScriptStruct_FArkFrame();
ARKLOGPLAYER_API UScriptStruct* Z_Construct_UScriptStruct_FArkVehicleState();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
UPackage* Z_Construct_UPackage__Script_ArkLogPlayer();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FArkVehicleState **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FArkVehicleState;
class UScriptStruct* FArkVehicleState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FArkVehicleState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FArkVehicleState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FArkVehicleState, (UObject*)Z_Construct_UPackage__Script_ArkLogPlayer(), TEXT("ArkVehicleState"));
	}
	return Z_Registration_Info_UScriptStruct_FArkVehicleState.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FArkVehicleState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Single vehicle state at a point in time (UE5 space: cm, left-handed). */" },
#endif
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single vehicle state at a point in time (UE5 space: cm, left-handed)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VehicleId_MetaData[] = {
		{ "Category", "Ark" },
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "Ark" },
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "Category", "Ark" },
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimestampNs_MetaData[] = {
		{ "Category", "Ark" },
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_VehicleId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TimestampNs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FArkVehicleState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_VehicleId = { "VehicleId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FArkVehicleState, VehicleId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VehicleId_MetaData), NewProp_VehicleId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FArkVehicleState, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FArkVehicleState, Rotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_TimestampNs = { "TimestampNs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FArkVehicleState, TimestampNs), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimestampNs_MetaData), NewProp_TimestampNs_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FArkVehicleState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_VehicleId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewProp_TimestampNs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FArkVehicleState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FArkVehicleState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ArkLogPlayer,
	nullptr,
	&NewStructOps,
	"ArkVehicleState",
	Z_Construct_UScriptStruct_FArkVehicleState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FArkVehicleState_Statics::PropPointers),
	sizeof(FArkVehicleState),
	alignof(FArkVehicleState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FArkVehicleState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FArkVehicleState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FArkVehicleState()
{
	if (!Z_Registration_Info_UScriptStruct_FArkVehicleState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FArkVehicleState.InnerSingleton, Z_Construct_UScriptStruct_FArkVehicleState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FArkVehicleState.InnerSingleton;
}
// ********** End ScriptStruct FArkVehicleState ****************************************************

// ********** Begin ScriptStruct FArkFrame *********************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FArkFrame;
class UScriptStruct* FArkFrame::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FArkFrame.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FArkFrame.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FArkFrame, (UObject*)Z_Construct_UPackage__Script_ArkLogPlayer(), TEXT("ArkFrame"));
	}
	return Z_Registration_Info_UScriptStruct_FArkFrame.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FArkFrame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One frame of telemetry: timestamp + all vehicle states for that frame. */" },
#endif
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One frame of telemetry: timestamp + all vehicle states for that frame." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimestampNs_MetaData[] = {
		{ "Category", "Ark" },
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vehicles_MetaData[] = {
		{ "Category", "Ark" },
		{ "ModuleRelativePath", "Public/ArkTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TimestampNs;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Vehicles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Vehicles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FArkFrame>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FArkFrame_Statics::NewProp_TimestampNs = { "TimestampNs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FArkFrame, TimestampNs), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimestampNs_MetaData), NewProp_TimestampNs_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FArkFrame_Statics::NewProp_Vehicles_Inner = { "Vehicles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FArkVehicleState, METADATA_PARAMS(0, nullptr) }; // 3562814615
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FArkFrame_Statics::NewProp_Vehicles = { "Vehicles", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FArkFrame, Vehicles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vehicles_MetaData), NewProp_Vehicles_MetaData) }; // 3562814615
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FArkFrame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FArkFrame_Statics::NewProp_TimestampNs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FArkFrame_Statics::NewProp_Vehicles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FArkFrame_Statics::NewProp_Vehicles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FArkFrame_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FArkFrame_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ArkLogPlayer,
	nullptr,
	&NewStructOps,
	"ArkFrame",
	Z_Construct_UScriptStruct_FArkFrame_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FArkFrame_Statics::PropPointers),
	sizeof(FArkFrame),
	alignof(FArkFrame),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FArkFrame_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FArkFrame_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FArkFrame()
{
	if (!Z_Registration_Info_UScriptStruct_FArkFrame.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FArkFrame.InnerSingleton, Z_Construct_UScriptStruct_FArkFrame_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FArkFrame.InnerSingleton;
}
// ********** End ScriptStruct FArkFrame ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkTypes_h__Script_ArkLogPlayer_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FArkVehicleState::StaticStruct, Z_Construct_UScriptStruct_FArkVehicleState_Statics::NewStructOps, TEXT("ArkVehicleState"), &Z_Registration_Info_UScriptStruct_FArkVehicleState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FArkVehicleState), 3562814615U) },
		{ FArkFrame::StaticStruct, Z_Construct_UScriptStruct_FArkFrame_Statics::NewStructOps, TEXT("ArkFrame"), &Z_Registration_Info_UScriptStruct_FArkFrame, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FArkFrame), 1972922861U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkTypes_h__Script_ArkLogPlayer_161228761(TEXT("/Script/ArkLogPlayer"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkTypes_h__Script_ArkLogPlayer_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkTypes_h__Script_ArkLogPlayer_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
