// // Copyright (c) 2025 YokaiProject inc.


#include "Animation/CAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCAnimInstance::NativeInitializeAnimation()
{
	UE_LOG(LogTemp, Log, TEXT("CAnimInstance::NativeInitializeAnimation"));
	OwnerCharacter = Cast<ACharacter>(GetOwningActor());
	if (OwnerCharacter)
	{
		UE_LOG(LogTemp, Log, TEXT("CAnimInstance::NativeInitializeAnimation: OwnerCharacter found"));
		OwnerCharacterMovementComp = OwnerCharacter->GetCharacterMovement();
	}
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	UE_LOG(LogTemp, Log, TEXT("CAnimInstance::NativeUpdateAnimation"));
	if (OwnerCharacter)
	{
		MovementSpeed = OwnerCharacter->GetVelocity().Length();
		FRotator Rotation = OwnerCharacter->GetActorRotation();
		FRotator DeltaRotation = UKismetMathLibrary::NormalizedDeltaRotator(
			Rotation, LastRotation
		);
		LastRotation = Rotation;

		YawSpeed = DeltaRotation.Yaw / DeltaSeconds;
		SmoothedYawSpeed =
			UKismetMathLibrary::FInterpTo(
				SmoothedYawSpeed,
				YawSpeed,
				DeltaSeconds,
				YawSpeedSmoothLerpSpeed);
	}

	if (OwnerCharacterMovementComp)
	{
		bIsFalling = OwnerCharacterMovementComp->IsFalling();
	}
}

void UCAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	UE_LOG(LogTemp, Log, TEXT("CAnimInstance::NativeThreadSafeUpdateAnimation"));
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
