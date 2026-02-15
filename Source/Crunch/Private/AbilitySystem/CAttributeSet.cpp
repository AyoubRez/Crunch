// // Copyright (c) 2025 YokaiProject inc.


#include "AbilitySystem/CAttributeSet.h"

#include "Net/UnrealNetwork.h"

UCAttributeSet::UCAttributeSet()
{
}

void UCAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCAttributeSet, Mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCAttributeSet, MaxMana, COND_None, REPNOTIFY_Always)
}

void UCAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCAttributeSet, Health, OldHealth);
}

void UCAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCAttributeSet, MaxHealth, OldMaxHealth);
}

void UCAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCAttributeSet, Mana, OldMana);
}

void UCAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCAttributeSet, MaxMana, OldMaxMana);
}
