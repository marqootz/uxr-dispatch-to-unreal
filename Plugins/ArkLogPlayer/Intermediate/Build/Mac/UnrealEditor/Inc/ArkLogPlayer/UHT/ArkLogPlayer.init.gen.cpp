// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeArkLogPlayer_init() {}
	ARKLOGPLAYER_API UFunction* Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature();
	ARKLOGPLAYER_API UFunction* Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ArkLogPlayer;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ArkLogPlayer()
	{
		if (!Z_Registration_Info_UPackage__Script_ArkLogPlayer.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkLogLoaded__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ArkLogPlayer_OnArkPlaybackTick__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ArkLogPlayer",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xD4213544,
				0x6C6EE32E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ArkLogPlayer.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ArkLogPlayer.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ArkLogPlayer(Z_Construct_UPackage__Script_ArkLogPlayer, TEXT("/Script/ArkLogPlayer"), Z_Registration_Info_UPackage__Script_ArkLogPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xD4213544, 0x6C6EE32E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
