// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinArenaGameMode.h"
#include "SpinArenaGameState.h"
#include "SpinArenaHUD.h"
#include "SpinArenaPlayerController.h"
#include "SpinArenaPlayerState.h"
#include "../../Player/BasePlayer.h"
#include "../../Interface/ControllerNotify.h"
#include "GameFramework/SpectatorPawn.h"
#include "Kismet/GameplayStatics.h"
#include "DreamArena/Extras/PlayerStart/GamePlayerStart.h"
#include "DreamArena/Extras/PlayerStart/ReadyPlayerStart.h"

ASpinArenaGameMode::ASpinArenaGameMode()
{

	static ConstructorHelpers::FClassFinder<ABasePlayer> DoubleSwordBPClass(TEXT("/Game/Blueprints/Player/BasePlayer_BP"));
	DoubleSwordClass = DoubleSwordBPClass.Class;

	DefaultPawnClass = ASpectatorPawn::StaticClass();
	PlayerControllerClass = ASpinArenaPlayerController::StaticClass();
	HUDClass = ASpinArenaHUD::StaticClass();
	GameStateClass = ASpinArenaGameState::StaticClass();
	PlayerStateClass = ASpinArenaPlayerState::StaticClass();

	MaxPlayerNumber = 2;
	ReadySpawnCount = 0;
	GameSpawnCount = 0;
	ReadyPlayerNums = 0;

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
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AReadyPlayerStart::StaticClass(), ReadyPlayerStarts);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGamePlayerStart::StaticClass(), GamePlayerStarts);

}

ABasePlayer* ASpinArenaGameMode::SpawnPawn(ERoleType RoleType)
{
	ABasePlayer* ReturnPlayer = nullptr;

	switch (RoleType)
	{
	case  ERoleType::DoubleSword:
	{
		if (ReadySpawnCount >= ReadyPlayerStarts.Num()) ReadySpawnCount = 0;
		ReturnPlayer = GetWorld()->SpawnActor<ABasePlayer>(DoubleSwordClass, ReadyPlayerStarts[ReadySpawnCount++]->GetActorTransform());
		break;
	}
	default:
		break;
	}
	if (++ReadyPlayerNums >= MaxPlayerNumber)
	{
		GameRoundBegin();
	}

	return ReturnPlayer;

}


void ASpinArenaGameMode::GameRoundBegin()
{

	if (ASpinArenaGameState* SpinArenaGameState = GetGameState<ASpinArenaGameState>()) SpinArenaGameState->SpinArenaGameStatus = ESpinArenaGameStatus::Gaming;

	GetWorld()->GetTimerManager().SetTimer(GameRoundBeginTimer, [this]() {
		GetWorld()->GetTimerManager().ClearTimer(GameRoundBeginTimer);
		GameRoundBeginDelegate.Broadcast();
		}, 1, false);

}

void ASpinArenaGameMode::AllocatePlayerTransform(AActor* InActor)
{
	if (ASpinArenaGameState* SpinArenaGameState = GetGameState<ASpinArenaGameState>())
	{
		if (SpinArenaGameState->SpinArenaGameStatus == ESpinArenaGameStatus::Ready)
		{
			if (ReadySpawnCount >= ReadyPlayerStarts.Num()) ReadySpawnCount = 0;
			InActor->SetActorTransform(ReadyPlayerStarts[ReadySpawnCount++]->GetActorTransform());
		}
		else if(SpinArenaGameState->SpinArenaGameStatus == ESpinArenaGameStatus::Gaming)
		{
			if (GameSpawnCount >= GamePlayerStarts.Num()) GameSpawnCount = 0;
			InActor->SetActorTransform(GamePlayerStarts[GameSpawnCount++]->GetActorTransform());
		}

	}

}
