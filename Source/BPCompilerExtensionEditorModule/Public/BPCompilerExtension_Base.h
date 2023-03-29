// Samurais 2021.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintCompilerExtension.h"
#include "BPCompilerExtension_Base.generated.h"

/**
 * 
 */
UCLASS()
class BPCOMPILEREXTENSIONEDITORMODULE_API UBPCompilerExtension_Base : public UBlueprintCompilerExtension
{
	GENERATED_BODY()

protected:
	virtual void ProcessBlueprintCompiled(const FKismetCompilerContext& CompilationContext, const FBlueprintCompiledData& Data) override;
	
public:
	// Classes that BPCompilerExtension will decide to check. I didn't find other way to make BlueprintCompilerExtension decide in advance when it should execute.
	TArray<UClass*> ClassesToCheck {};
};


