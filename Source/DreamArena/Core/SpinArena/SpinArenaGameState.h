// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DreamArena/DreamArena.h"
#include "SpinArenaGameState.generated.h"

/**
 * 
 */
UCLASS()
class DREAMARENA_API ASpinArenaGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	ASpinArenaGameState();

	

	ESpinArenaGameStatus SpinArenaGameStatus;

	// 对局场数
	uint8 GameNumber;

	// 最大对局 场数 奇数
	uint8 MaxGameNumber;
	
};
