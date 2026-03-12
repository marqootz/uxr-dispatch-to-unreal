// Copyright Ark. Ark Log Player plugin.

using UnrealBuildTool;

public class ArkLogPlayer : ModuleRules
{
	public ArkLogPlayer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"Json",
			"JsonUtilities",
			"ProceduralMeshComponent"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
