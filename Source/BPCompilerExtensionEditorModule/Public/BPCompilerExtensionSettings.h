// Samurais 2021.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BPCompilerExtensionSettings.generated.h"

class UBPCompilerExtension_Base;

// Created because TMap doesn't support nesting containers. (In simple words no TArray and etc. in TMap)
USTRUCT(BlueprintType)
struct FClassesToUseCompilerExtensionWith
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<UClass*> Classes;
};

/**
 * 
 */
UCLASS(config = BPCompilerExtensionSettings)
class BPCOMPILEREXTENSIONEDITORMODULE_API UBPCompilerExtensionSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere)
	TMap<TSubclassOf<UBPCompilerExtension_Base>, FClassesToUseCompilerExtensionWith> BPCompilerExtension_Classes_Map;
};

