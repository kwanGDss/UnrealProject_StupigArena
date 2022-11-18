// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnSaveAttackDelegate);
DECLARE_MULTICAST_DELEGATE(FOnResetAttackDelegate);

/**
 *
 */
UCLASS()
class STUPIGARENA_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	FOnSaveAttackDelegate OnSaveAttack;
	FOnResetAttackDelegate OnResetAttack;

private:
	UFUNCTION()
	void AnimNotify_SaveAttack();

	UFUNCTION()
	void AnimNotify_ResetCombo();
};
