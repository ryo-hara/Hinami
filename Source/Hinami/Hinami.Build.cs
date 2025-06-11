// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Hinami : ModuleRules
{
	public Hinami(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
