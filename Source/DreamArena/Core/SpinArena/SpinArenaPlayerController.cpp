// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinArenaPlayerController.h"
#include "SpinArenaHUD.h"
#include "DreamArena/DreamArena.h"
#include "SpinArenaGameMode.h"
#include "../../Player/BasePlayer.h"



void ASpinArenaPlayerController::SucceedJoinGame_Implementation()
{
	SucceedJoinGameOnClient();


}

void ASpinArenaPlayerController::SucceedJoinGameOnClient_Implementation()
{

	if (ASpinArenaHUD* SpinArenaHUD = GetHUD<ASpinArenaHUD>())
	{

		this->bShowMouseCursor = true;
		SpinArenaHUD->ShowSelectPlayerMenu();

	}
}

void ASpinArenaPlayerController::SpawnAndControlPawn(ERoleType RoleType)
{
	this->bShowMouseCursor = false;

	SpawnAndControlPawn_OnServer(RoleType);
}

void ASpinArenaPlayerController::SpawnAndControlPawn_OnServer_Implementation(ERoleType RoleType)
{
	UE_LOG(LogTemp, Warning, TEXT(" ASpinArenaPlayerController::SpawnAndControlPawn_OnServer_Implementation()"));
	if (ASpinArenaGameMode* SpinArenaGameMode = GetWorld()->GetAuthGameMode<ASpinArenaGameMode>())
	{
		if (ABasePlayer* MyPlayer = SpinArenaGameMode->SpawnPawn(RoleType))
		{

			APawn* TempPawn = GetPawn();
			this->Possess(MyPlayer);

			if (TempPawn)
			{
				if (ABasePlayer* TempBasePlayer = Cast<ABasePlayer>(TempPawn))
				{
					TempBasePlayer->DestroyPlayer();
				}
				else
				{
					TempPawn->Destroy();
				}

			}
			
		}

	}

}
