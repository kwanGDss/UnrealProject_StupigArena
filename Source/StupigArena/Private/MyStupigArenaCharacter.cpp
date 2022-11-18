// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStupigArenaCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyAnimInstance.h"


AMyStupigArenaCharacter::AMyStupigArenaCharacter()
{
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -97.0f), FRotator(0.0f, -90.0f, 0.0f));

	GetFollowCamera()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 200.0f), FRotator(-25.0f, 0.0f, 0.0f));
	GetCameraBoom()->TargetArmLength = 300.0f;

	GetCharacterMovement()->JumpZVelocity = 300.0f;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_Drongo(TEXT("/Game/ParagonDrongo/Characters/Heroes/Drongo/Meshes/Drongo_GDC"));
	if (SK_Drongo.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_Drongo.Object);
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> ABP_Drongo(TEXT("/Game/ParagonDrongo/Characters/Heroes/Drongo/Drongo_AnimBlueprint"));
	if (ABP_Drongo.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(ABP_Drongo.Class);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM_Drongo(TEXT("/Game/ParagonDrongo/Characters/Heroes/Drongo/Animations/Primary_Fire_Montage"));
	if (AM_Drongo.Succeeded())
	{
		AttackMontage = AM_Drongo.Object;
	}

	bIsAttacking = false;
	bSaveAttack = false;
	AttackCount = 0;
}

void AMyStupigArenaCharacter::ComboAttackSave()
{
	if(bSaveAttack)
	{
		bSaveAttack = false;

		switch(AttackCount)
		{
		case 0:
			AttackCount = 1;
			PlayAnimMontage(AttackMontage);
			break;
		case 1:
			AttackCount = 0;
			PlayAnimMontage(AttackMontage);
			break;
		default:
			break;
		}
	}
}

void AMyStupigArenaCharacter::ResetCombo()
{
	AttackCount = 0;
	bSaveAttack = false;
	bIsAttacking = false;
}

void AMyStupigArenaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyStupigArenaCharacter::Attack);
}

void AMyStupigArenaCharacter::Attack()
{
	if(bIsAttacking)
	{
		bSaveAttack = true;
	}
	else
	{
		bIsAttacking = true;

		switch (AttackCount)
		{
		case 0:
			AttackCount = 1;
			PlayAnimMontage(AttackMontage);
			break;
		case 1:
			AttackCount = 0;
			PlayAnimMontage(AttackMontage);
			break;
		default:
			break;
		}
	}
}
