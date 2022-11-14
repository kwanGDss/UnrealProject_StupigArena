// Copyright Epic Games, Inc. All Rights Reserved.

#include "StupigArenaGameMode.h"
#include "StupigArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyStupigArenaCharacter.h"

AStupigArenaGameMode::AStupigArenaGameMode()
{
	// set default pawn class to our Blueprinted character
	DefaultPawnClass = AMyStupigArenaCharacter::StaticClass();
}
