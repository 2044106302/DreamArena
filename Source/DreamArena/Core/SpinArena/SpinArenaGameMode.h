// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpinArenaGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DREAMARENA_API ASpinArenaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASpinArenaGameMode();
	

protected:

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;

	virtual void StartPlay() override;



};
