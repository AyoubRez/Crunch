// // Copyright (c) 2025 YokaiProject inc.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class UCAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	ATTRIBUTE_ACCESSORS(UCAttributeSet, HealthAttribute)
	ATTRIBUTE_ACCESSORS(UCAttributeSet, MaxHealthAttribute)
	ATTRIBUTE_ACCESSORS(UCAttributeSet, ManaAttribute)
	ATTRIBUTE_ACCESSORS(UCAttributeSet, MaxManaAttribute)

private:
	UPROPERTY()
	FGameplayAttributeData HealthAttribute;

	UPROPERTY()
	FGameplayAttributeData MaxHealthAttribute;

	UPROPERTY()
	FGameplayAttributeData ManaAttribute;

	UPROPERTY()
	FGameplayAttributeData MaxManaAttribute;
};
