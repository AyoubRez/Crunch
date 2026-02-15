// // Copyright (c) 2025 YokaiProject inc.


#include "AbilitySystem/CAbilitySystemComponent.h"

void UCAbilitySystemComponent::ApplyInitialEffects()
{
	if (!GetOwner() || !GetOwner()->HasAuthority()) return;
	UE_LOG(LogTemp, Log, TEXT("Applying initial effects..."));
	for (const auto& EffectClass : InitialEffects)
	{
		// Create Gameplay effect Context handle
		const FGameplayEffectContextHandle ContextHandle = MakeEffectContext();

		// Create a Gameplay effect Spec handle with MakeOutgoingSpec
		FGameplayEffectSpecHandle SpecHandle =
			MakeOutgoingSpec(EffectClass, 1.f, ContextHandle);

		// Apply Gameplay effect Spec
		ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}
