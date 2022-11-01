// Samurais 2021.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorWithoutSMC.generated.h"

class USkeletalMeshComponent;

UCLASS()
class BCE_PROJECT_API AActorWithoutSMC : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorWithoutSMC();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
