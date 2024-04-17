// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DreamArena/DreamArena.h"
#include "SpinArenaGameMode.generated.h"

class ABasePlayer;
UCLASS()
class DREAMARENA_API ASpinArenaGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	TSubclassOf<ABasePlayer> DoubleSwordClass;



public:
	ASpinArenaGameMode();
	

protected:

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;

	virtual void StartPlay() override;


protected:






	// 最大玩家个数
	uint8 MaxPlayerNumber;

public:
	ABasePlayer* SpawnPawn(ERoleType RoleType);



};
