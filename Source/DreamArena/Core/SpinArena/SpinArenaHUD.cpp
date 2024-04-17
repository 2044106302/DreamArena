// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinArenaHUD.h"
#include "SpinArenaPlayerController.h"
#include "../../Extras/SpinArena/UI/UI_SpinArenaMain.h"

ASpinArenaHUD::ASpinArenaHUD()
{
	static ConstructorHelpers::FClassFinder<UUI_SpinArenaMain> SpinArenaMainBPClass(TEXT("/Game/Blueprints/Extras/SpinArena/UI/UI_SpinArenaMain_BP"));
	SpinArenaMainClass = SpinArenaMainBPClass.Class;

}

void ASpinArenaHUD::ShowSelectPlayerMenu()
{
	if (SpinArenaMain)
	{
		SpinArenaMain->ShowSelectPlayerMenu();
	}
	else
	{

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
			ShowSelectPlayerMenu();			
			},0.3f,false);

	}


}

void ASpinArenaHUD::BeginPlay()
{
	Super::BeginPlay();

	if (SpinArenaMainClass)
	{
		SpinArenaMain = CreateWidget<UUI_SpinArenaMain>(GetWorld(), SpinArenaMainClass);
		if (SpinArenaMain)
		{
			SpinArenaMain->AddToViewport();
		}
	}

}
