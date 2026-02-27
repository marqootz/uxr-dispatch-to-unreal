// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArkVehicleDriveComponent.h"
#include "ArkTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeArkVehicleDriveComponent() {}

// ********** Begin Cross Module References ********************************************************
ARKLOGPLAYER_API UClass* Z_Construct_UClass_UArkVehicleDriveComponent();
ARKLOGPLAYER_API UClass* Z_Construct_UClass_UArkVehicleDriveComponent_NoRegister();
ARKLOGPLAYER_API UScriptStruct* Z_Construct_UScriptStruct_FArkVehicleState();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_ArkLogPlayer();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UArkVehicleDriveComponent ************************************************
void UArkVehicleDriveComponent::StaticRegisterNativesUArkVehicleDriveComponent()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UArkVehicleDriveComponent;
UClass* UArkVehicleDriveComponent::GetPrivateStaticClass()
{
	using TClass = UArkVehicleDriveComponent;
	if (!Z_Registration_Info_UClass_UArkVehicleDriveComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ArkVehicleDriveComponent"),
			Z_Registration_Info_UClass_UArkVehicleDriveComponent.InnerSingleton,
			StaticRegisterNativesUArkVehicleDriveComponent,
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
	return Z_Registration_Info_UClass_UArkVehicleDriveComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UArkVehicleDriveComponent_NoRegister()
{
	return UArkVehicleDriveComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UArkVehicleDriveComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Attach to a vehicle Actor. Set VehicleId (Blueprint or at spawn); each tick\n * fetches interpolated state from the log player subsystem and sets the Actor's\n * location and rotation.\n */" },
#endif
		{ "IncludePath", "ArkVehicleDriveComponent.h" },
		{ "ModuleRelativePath", "Public/ArkVehicleDriveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attach to a vehicle Actor. Set VehicleId (Blueprint or at spawn); each tick\nfetches interpolated state from the log player subsystem and sets the Actor's\nlocation and rotation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VehicleId_MetaData[] = {
		{ "Category", "Ark" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Vehicle id matching the log's statuses[].id. */" },
#endif
		{ "ModuleRelativePath", "Public/ArkVehicleDriveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vehicle id matching the log's statuses[].id." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastState_MetaData[] = {
		{ "Category", "Ark" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Last state applied (for debug). */" },
#endif
		{ "ModuleRelativePath", "Public/ArkVehicleDriveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Last state applied (for debug)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasValidState_MetaData[] = {
		{ "Category", "Ark" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True when we have valid state from the subsystem this tick. */" },
#endif
		{ "ModuleRelativePath", "Public/ArkVehicleDriveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True when we have valid state from the subsystem this tick." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_VehicleId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastState;
	static void NewProp_bHasValidState_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasValidState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UArkVehicleDriveComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_VehicleId = { "VehicleId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkVehicleDriveComponent, VehicleId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VehicleId_MetaData), NewProp_VehicleId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_LastState = { "LastState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UArkVehicleDriveComponent, LastState), Z_Construct_UScriptStruct_FArkVehicleState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastState_MetaData), NewProp_LastState_MetaData) }; // 3562814615
void Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_bHasValidState_SetBit(void* Obj)
{
	((UArkVehicleDriveComponent*)Obj)->bHasValidState = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_bHasValidState = { "bHasValidState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UArkVehicleDriveComponent), &Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_bHasValidState_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasValidState_MetaData), NewProp_bHasValidState_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UArkVehicleDriveComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_VehicleId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_LastState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UArkVehicleDriveComponent_Statics::NewProp_bHasValidState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UArkVehicleDriveComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UArkVehicleDriveComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ArkLogPlayer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UArkVehicleDriveComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UArkVehicleDriveComponent_Statics::ClassParams = {
	&UArkVehicleDriveComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UArkVehicleDriveComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UArkVehicleDriveComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UArkVehicleDriveComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UArkVehicleDriveComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UArkVehicleDriveComponent()
{
	if (!Z_Registration_Info_UClass_UArkVehicleDriveComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UArkVehicleDriveComponent.OuterSingleton, Z_Construct_UClass_UArkVehicleDriveComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UArkVehicleDriveComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UArkVehicleDriveComponent);
UArkVehicleDriveComponent::~UArkVehicleDriveComponent() {}
// ********** End Class UArkVehicleDriveComponent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkVehicleDriveComponent_h__Script_ArkLogPlayer_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UArkVehicleDriveComponent, UArkVehicleDriveComponent::StaticClass, TEXT("UArkVehicleDriveComponent"), &Z_Registration_Info_UClass_UArkVehicleDriveComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UArkVehicleDriveComponent), 884188466U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkVehicleDriveComponent_h__Script_ArkLogPlayer_2552407142(TEXT("/Script/ArkLogPlayer"),
	Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkVehicleDriveComponent_h__Script_ArkLogPlayer_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_markmanfrey_LOCAL_DEV_UNREAL_dev_dispatch_Plugins_ArkLogPlayer_Source_ArkLogPlayer_Public_ArkVehicleDriveComponent_h__Script_ArkLogPlayer_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
