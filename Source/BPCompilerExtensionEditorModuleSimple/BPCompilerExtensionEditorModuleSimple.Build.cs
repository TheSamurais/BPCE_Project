// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BPCompilerExtensionEditorModuleSimple : ModuleRules
{
	public BPCompilerExtensionEditorModuleSimple(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore"  });
		
		PrivateDependencyModuleNames.AddRange(new string[] {"UnrealEd", "Kismet", "KismetCompiler", "BCE_Project"});
	}
}
