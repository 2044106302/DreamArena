// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../../Interface/ControllerNotify.h"
#include "DreamArena/DreamArena.h"
#include "SpinArenaPlayerController.generated.h"



UCLASS()
class DREAMARENA_API ASpinArenaPlayerController : public APlayerController, public IControllerNotify
{
	GENERATED_BODY()

protected:

protected:

	virtual void SucceedJoinGame_Implementation() override;



public:
	UFUNCTION(Client,Reliable)
 	void SucceedJoinGameOnClient();

	void SpawnAndControlPawn(ERoleType RoleType);


	UFUNCTION(Server,Reliable)
	void SpawnAndControlPawn_OnServer(ERoleType RoleType);
	
};
