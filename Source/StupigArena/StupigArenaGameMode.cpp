// Copyright Epic Games, Inc. All Rights Reserved.

#include "StupigArenaGameMode.h"
#include "StupigArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStupigArenaGameMode::AStupigArenaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
