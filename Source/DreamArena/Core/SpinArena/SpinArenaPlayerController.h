// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DreamArena/Interface/ControllerNotify.h"
#include "DreamArena/DreamArena.h"
#include "SpinArenaPlayerController.generated.h"



UCLASS()
class DREAMARENA_API ASpinArenaPlayerController : public APlayerController, public IControllerNotify
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:

	virtual void SucceedJoinGame_Implementation() override;

public:
	UFUNCTION(Client,Reliable)
 	void SucceedJoinGameOnClient();

	void SpawnAndControlPawn(ERoleType RoleType);


	UFUNCTION(Server,Reliable)
	void SpawnAndControlPawn_OnServer(ERoleType RoleType);
	


	FDelegateHandle GameRoundBeginHandle;
	void GameRoundBegin();


	// GotoReady
	FDelegateHandle GameRoundEndHandle;
	void GameRoundEnd();

};
