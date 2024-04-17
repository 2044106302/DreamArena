// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SpinArenaHUD.generated.h"

class UUI_SpinArenaMain;

UCLASS()
class DREAMARENA_API ASpinArenaHUD : public AHUD
{
	GENERATED_BODY()

public:
	ASpinArenaHUD();

public:
	
	void ShowSelectPlayerMenu();

	virtual void BeginPlay() override;



	UPROPERTY()
	TSubclassOf<UUI_SpinArenaMain> SpinArenaMainClass;


	UPROPERTY()
	TObjectPtr<UUI_SpinArenaMain> SpinArenaMain;

	FTimerHandle TimerHandle;


};
