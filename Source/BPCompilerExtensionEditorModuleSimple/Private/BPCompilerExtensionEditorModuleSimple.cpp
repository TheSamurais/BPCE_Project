// Samurais 2021.

#include "BPCompilerExtensionEditorModuleSimple.h"

#include "BlueprintCompilationManager.h"
#include "BPCompilerExtension_BaseSimple.h"

void FBPCompilerExtensionEditorModuleSimple::StartupModule()
{
	// Create our BPCompilerExtension object and register it in CompilationManager.
	UBPCompilerExtension_BaseSimple* CompilerExtensionObject = NewObject<UBPCompilerExtension_BaseSimple> ();
	FBlueprintCompilationManager::RegisterCompilerExtension(UBlueprint::StaticClass(), CompilerExtensionObject);
}

void FBPCompilerExtensionEditorModuleSimple::ShutdownModule()
{
}

IMPLEMENT_MODULE(FBPCompilerExtensionEditorModuleSimple, BPCompilerExtensionEditorModuleSimple);




