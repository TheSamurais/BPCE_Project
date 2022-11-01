// Samurais 2021.

#pragma once

#include "Modules/ModuleInterface.h"

class FBPCompilerExtensionEditorModuleSimple : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
