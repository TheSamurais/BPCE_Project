// Samurais 2021.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintCompilationManager.h"

#include "BPCompilerExtensionSettings.h"
#include "BPCompilerExtension_Base.h"

// Created to separate more complex logic from Module class.
class CompilerExtensionRegisterer
{
public:
	static void AddBPExtension(UBPCompilerExtensionSettings* BPCompilerExtensionSettings)
	{
		// For every compilerExtension class create object and fill in its fields.
		for(const auto BPExtensionClassesPair : BPCompilerExtensionSettings->BPCompilerExtension_Classes_Map)
		{
			if(!BPExtensionClassesPair.Key)
			{
				UE_LOG(BPCompilerExtension, Error, TEXT("BPExtensionClassesPairs key is empty."));
				continue;
			}
			if(!BPExtensionClassesPair.Value.Classes.IsValidIndex(0) || !BPExtensionClassesPair.Value.Classes[0])
			{
				UE_LOG(BPCompilerExtension, Error, TEXT("BPExtensionClassesPairs value is not filled proeprly."));
				continue;
			}
			
			// Create object with usage of GetTransientPackage as this is perfect method for that kind of object.
			// It would be used by default but here we want to pass UClass to make a object of it.
			UBPCompilerExtension_Base* CompilerExtensionObject =
				NewObject<UBPCompilerExtension_Base> ((UObject*)GetTransientPackage(), BPExtensionClassesPair.Key);
			
			if(!CompilerExtensionObject)
			{
				UE_LOG(BPCompilerExtension, Error, TEXT("Failed to create object."));
				continue;
			}

			// Fill CompilerExtension variable.
			CompilerExtensionObject->ClassesToCheck = BPExtensionClassesPair.Value.Classes;
			
			FBlueprintCompilationManager::RegisterCompilerExtension(UBlueprint::StaticClass(), CompilerExtensionObject);
		}
	}
};
