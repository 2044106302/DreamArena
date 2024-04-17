// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SpinArenaPlayerState.generated.h"


UCLASS()
class DREAMARENA_API ASpinArenaPlayerState : public APlayerState
{

	GENERATED_BODY()

public:
	





protected:


	// 当前赢得的 回合数
	uint8 WinGameRound;

};
