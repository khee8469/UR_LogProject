// Copyright Epic Games, Inc. All Rights Reserved.

#include "UR_LogProjectGameMode.h"
#include "UR_LogProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUR_LogProjectGameMode::AUR_LogProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
