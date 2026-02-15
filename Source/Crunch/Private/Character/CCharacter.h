// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CCharacter.generated.h"

UCLASS()
class ACCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACCharacter();
	void ServerSideInit();
	void ClientSideInit();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/********************************************************************/
	/*                     Gameplay Ability                             */
	/********************************************************************/

public:
	/** Start IAbilitySystemInterface **/
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** End IAbilitySystemInterface **/

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Gameplay Ability")
	class UCAbilitySystemComponent* CAbilitySystemComponent;

	UPROPERTY()
	class UCAttributeSet* CAttributeSet;
};
