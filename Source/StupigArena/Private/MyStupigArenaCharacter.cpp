// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStupigArenaCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMyStupigArenaCharacter::AMyStupigArenaCharacter()
{
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -97.0f), FRotator(0.0f, -90.0f, 0.0f));

	GetFollowCamera()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 200.0f), FRotator(-25.0f, 0.0f, 0.0f));
	GetCameraBoom()->TargetArmLength = 300.0f;

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
}
