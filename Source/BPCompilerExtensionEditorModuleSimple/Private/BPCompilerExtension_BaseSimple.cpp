// Samurais 2022.

#include "BPCompilerExtension_BaseSimple.h"

// Class we want to check.
#include "ActorWithoutSMC.h"

// includes for digging out array with components.
#include "KismetCompiler/Public/KismetCompiler.h"
#include "Engine/SimpleConstructionScript.h"
#include "Engine/SCS_Node.h"

// includes for logging out message/error.
#include "Kismet2/CompilerResultsLog.h"
#include "Logging/TokenizedMessage.h"


void UBPCompilerExtension_BaseSimple::ProcessBlueprintCompiled(const FKismetCompilerContext& CompilationContext, const FBlueprintCompiledData& Data)
{
	// Check if compiled BP is child of class we want to check.
	if(CompilationContext.Blueprint->ParentClass->IsChildOf(AActorWithoutSMC::StaticClass()))
	{
		if(const TObjectPtr<USimpleConstructionScript> SimpleConstructionScript = CompilationContext.Blueprint->SimpleConstructionScript)
		{
			// SCS stores data needed to replicate components in BP in so called Nodes (one node per component).
			TArray<USCS_Node*> SCS_Nodes = SimpleConstructionScript->GetAllNodes();
			for(const USCS_Node* SCS_Node : SCS_Nodes)
			{
				// Acquiring component from SCS_Node and casting it to StaticMeshComponent (if success fail compilation).
				if(SCS_Node)
					if(Cast<UStaticMeshComponent> (SCS_Node->ComponentTemplate))
					{
						/*	Fail BP compilation and print message on PIE but when packaging game DON'T FAIL.
						 *	
						 *	CompilationContext.MessageLog.AddTokenizedMessage(FTokenizedMessage::Create(
						 *		EMessageSeverity::Error,
						 *		FText::FromString("Don't use StaticMeshComponent with this actor.")));
						 */

						// Fail BP compilation, print message on PIE and fail when trying to package game.
						CompilationContext.MessageLog.Error(TEXT("Don't use StaticMeshComponent with this actor."));
					}
			}
		}
	}
}