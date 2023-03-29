// Copyright Epic Games, Inc. All Rights Reserved.

#include "BCE_ProjectGameMode.h"
#include "BCE_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABCE_ProjectGameMode::ABCE_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
