// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinArenaGameMode.h"
#include "SpinArenaGameState.h"
#include "SpinArenaHUD.h"
#include "SpinArenaPlayerController.h"
#include "SpinArenaPlayerState.h"

ASpinArenaGameMode::ASpinArenaGameMode()
{
	DefaultPawnClass = nullptr;
	PlayerControllerClass = ASpinArenaPlayerController::StaticClass();
	HUDClass = ASpinArenaHUD::StaticClass();
	GameStateClass = ASpinArenaGameState::StaticClass();
	PlayerStateClass = ASpinArenaPlayerState::StaticClass();
}

void ASpinArenaGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	UE_LOG(LogTemp, Warning, TEXT("ASpinArenaGameMode::PostLogin"));

}

void ASpinArenaGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	UE_LOG(LogTemp, Warning, TEXT("ASpinArenaGameMode::Logout"));
}

void ASpinArenaGameMode::StartPlay()
{
	Super::StartPlay();

	UE_LOG(LogTemp, Warning, TEXT("ASpinArenaGameMode::StartPlay"));
}
