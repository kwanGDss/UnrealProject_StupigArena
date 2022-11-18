// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

void UMyAnimInstance::AnimNotify_SaveAttack()
{
	OnSaveAttack.Broadcast();
}

void UMyAnimInstance::AnimNotify_ResetCombo()
{
	OnResetAttack.Broadcast();
}
