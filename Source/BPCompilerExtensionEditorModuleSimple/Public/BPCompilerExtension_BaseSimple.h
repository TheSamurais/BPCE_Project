// Samurais 2022.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintCompilerExtension.h"
#include "BPCompilerExtension_BaseSimple.generated.h"

/**
 * 
 */
UCLASS()
class BPCOMPILEREXTENSIONEDITORMODULESIMPLE_API UBPCompilerExtension_BaseSimple : public UBlueprintCompilerExtension
{
	GENERATED_BODY()

protected:
	/**
	 * Override this if you're interested in running logic after class layout has been
	 * generated, but before bytecode and member variables have been 
	 */
	virtual void ProcessBlueprintCompiled(const FKismetCompilerContext& CompilationContext, const FBlueprintCompiledData& Data) override;
};


