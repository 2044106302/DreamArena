// Fill out your copyright notice in the Description page of Project Settings.


#include "HallGameMode.h"
#include "HallPlayerController.h"
#include "HallHUD.h"

AHallGameMode::AHallGameMode()
{
	HUDClass = AHallHUD::StaticClass();
	PlayerControllerClass = AHallPlayerController::StaticClass();
	DefaultPawnClass = nullptr;
	
}
