// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStupigArenaCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


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
	if (bSaveAttack)
	{
		bSaveAttack = false;

		PlayAttackMontage();
	}
}

void AMyStupigArenaCharacter::ResetCombo()
{
	AttackCount = 0;
	bSaveAttack = false;
	bIsAttacking = false;
}

void AMyStupigArenaCharacter::Fire()
{
	FHitResult HitResult;
	FVector StartedFire = UKismetMathLibrary::TransformLocation(GetActorTransform(), FVector(100.0f, 20.0f, 57.0f));
	FVector EndedFire = GetActorForwardVector() * 15000.0f + StartedFire;
	TArray<AActor*> IgnoreActors;

	UKismetSystemLibrary::LineTraceSingleByProfile(GetWorld(), StartedFire, EndedFire, "Fire", false, IgnoreActors, EDrawDebugTrace::ForOneFrame, HitResult, true);
	UKismetSystemLibrary::DrawDebugBox(GetWorld(), StartedFire, FVector::OneVector, FLinearColor::Red, FRotator::ZeroRotator, 10.0f);
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Fire"));
}

void AMyStupigArenaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyStupigArenaCharacter::Attack);
}

void AMyStupigArenaCharacter::PlayAttackMontage()
{
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

void AMyStupigArenaCharacter::Attack()
{
	if (bIsAttacking)
	{
		bSaveAttack = true;
	}
	else
	{
		bIsAttacking = true;

		PlayAttackMontage();
	}
}
