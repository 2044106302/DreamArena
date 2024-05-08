// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DreamArena/DreamArena.h"
#include "SpinArenaGameMode.generated.h"


DECLARE_MULTICAST_DELEGATE(FSpinGameRoundBegin);




class ABasePlayer;
UCLASS()
class DREAMARENA_API ASpinArenaGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:


	UPROPERTY()
	TSubclassOf<ABasePlayer> DoubleSwordClass;


	UPROPERTY()
	TArray<AActor*> ReadyPlayerStarts;
	uint8  ReadySpawnCount;

	UPROPERTY()
	TArray<AActor*> GamePlayerStarts;
	uint8 GameSpawnCount;

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

	uint8 ReadyPlayerNums;

	ABasePlayer* SpawnPawn(ERoleType RoleType);


public:

	FSpinGameRoundBegin GameRoundBeginDelegate;

	// 回合开始
	void GameRoundBegin();

	void AllocatePlayerTransform(AActor* InActor);

protected:
	FTimerHandle GameRoundBeginTimer;
};
