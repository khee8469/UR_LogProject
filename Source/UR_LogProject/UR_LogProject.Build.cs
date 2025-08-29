// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UR_LogProject : ModuleRules
{
	public UR_LogProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
