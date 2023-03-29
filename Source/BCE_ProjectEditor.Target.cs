// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BCE_ProjectEditorTarget : TargetRules
{
	public BCE_ProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("BCE_Project");
		
		ExtraModuleNames.Add("BPCompilerExtensionEditorModuleSimple");
		ExtraModuleNames.Add("BPCompilerExtensionEditorModule");
	}
}
