// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinArenaGameMode.h"
#include "SpinArenaGameState.h"
#include "SpinArenaHUD.h"
#include "SpinArenaPlayerController.h"
#include "SpinArenaPlayerState.h"
#include "../../Player/BasePlayer.h"
#include "../../Interface/ControllerNotify.h"
#include "GameFramework/SpectatorPawn.h"

ASpinArenaGameMode::ASpinArenaGameMode()
{

	static ConstructorHelpers::FClassFinder<ABasePlayer> DoubleSwordBPClass(TEXT("/Game/Blueprints/Player/BasePlayer_BP"));
	DoubleSwordClass = DoubleSwordBPClass.Class;

	DefaultPawnClass = ASpectatorPawn::StaticClass();
	PlayerControllerClass = ASpinArenaPlayerController::StaticClass();
	HUDClass = ASpinArenaHUD::StaticClass();
	GameStateClass = ASpinArenaGameState::StaticClass();
	PlayerStateClass = ASpinArenaPlayerState::StaticClass();


	

}

void ASpinArenaGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (NewPlayer && NewPlayer->GetClass()->ImplementsInterface(UControllerNotify::StaticClass()))
	{
		if (IControllerNotify* ControllerNotify_BPI = CastChecked<IControllerNotify>(NewPlayer))
		{
			ControllerNotify_BPI->Execute_SucceedJoinGame(NewPlayer);
		}
	}

}

void ASpinArenaGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);


}

void ASpinArenaGameMode::StartPlay()
{
	Super::StartPlay();


}

ABasePlayer* ASpinArenaGameMode::SpawnPawn(ERoleType RoleType)
{

	if (DoubleSwordClass)
	{
		UE_LOG(LogTemp, Warning, TEXT(" DoubleSwordClass"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" DoubleSwordClass nullptr"));
	}

	switch (RoleType)
	{
	case  ERoleType::DoubleSword:
	{
		return GetWorld()->SpawnActor<ABasePlayer>(DoubleSwordClass);
		break;
	}
	default:
		break;
	}
	return nullptr;

}
