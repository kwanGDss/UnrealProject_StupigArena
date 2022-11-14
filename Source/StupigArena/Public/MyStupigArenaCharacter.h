// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StupigArenaCharacter.h"
#include "MyStupigArenaCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUPIGARENA_API AMyStupigArenaCharacter : public AStupigArenaCharacter
{
	GENERATED_BODY()

public:
	AMyStupigArenaCharacter();

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();

private:

	bool bIsAttacking;
	bool bSaveAttack;
	int attackCount;
};
