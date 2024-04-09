// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class DREAMARENA_API ASword : public ABaseWeapon
{
	GENERATED_BODY()

public:

	ASword();

	virtual void StartAttack() override;
	
};
