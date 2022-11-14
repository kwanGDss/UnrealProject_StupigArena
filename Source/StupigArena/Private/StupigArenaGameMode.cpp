// Copyright Epic Games, Inc. All Rights Reserved.

#include "StupigArenaGameMode.h"
#include "StupigArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyStupigArenaCharacter.h"


AStupigArenaGameMode::AStupigArenaGameMode()
{
	// set default pawn class to our Blueprinted character
	DefaultPawnClass = AMyStupigArenaCharacter::StaticClass();
	//static ConstructorHelpers::FClassFinder<APawn> BP_Drongo(TEXT("/Game/ParagonDrongo/Characters/Heroes/Drongo/DrongoPlayerCharacter"));
	//if (BP_Drongo.Succeeded())
	//{
	//	DefaultPawnClass = BP_Drongo.Class;
	//}
}
