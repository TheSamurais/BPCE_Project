// Samurais 2022.

#include "BPCompilerExtensionEditorModule.h"

#include "CompilerExtensionRegisterer.h"
#include "Modules/ModuleManager.h"
#include "ISettingsModule.h"

#include "BPCompilerExtensionSettings.h"

DEFINE_LOG_CATEGORY(BPCompilerExtension);

void FBPCompilerExtensionEditorModule::StartupModule()
{
	// Register module settings in ProjectSettings.
	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule> ("Settings"))
	{
		SettingsModule->RegisterSettings(FName("Project"), FName("Editor"), FName("BPCompilerExtension"),
										FText::FromString("BPCompilerExtension"),
										FText::FromString("After filling variables first time you need to restart editor for all the code to start working."),
										GetMutableDefault<UBPCompilerExtensionSettings> ());
	}

	// Acquire BPCSettings to pass them to static method defined in CompilerExtensionInterface.
	UBPCompilerExtensionSettings* BPCompilerExtensionSettings = GetMutableDefault<UBPCompilerExtensionSettings> ();
	// Adding BPCompilerExtension here makes it register only once(every other place I tried ended with at least 2 calls).
	CompilerExtensionRegisterer::AddBPExtension(BPCompilerExtensionSettings);
}

void FBPCompilerExtensionEditorModule::ShutdownModule()
{
	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule> ("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Editor", "BPCompilerExtension");
	}
}

IMPLEMENT_MODULE(FBPCompilerExtensionEditorModule, BPCompilerExtensionEditorModule);




