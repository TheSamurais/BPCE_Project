// Samurais 2021.

#include "ActorWithoutSMC.h"


AActorWithoutSMC::AActorWithoutSMC()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AActorWithoutSMC::BeginPlay()
{
	Super::BeginPlay();
	
}

void AActorWithoutSMC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

