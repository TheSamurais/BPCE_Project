// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BCE_Project : ModuleRules
{
	public BCE_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		
	}
}
