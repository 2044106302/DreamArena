// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SelectRole.h"
#include "Components/Button.h"
#include "DreamArena/DreamArena.h"
#include "../../../Core/SpinArena/SpinArenaPlayerController.h"
#include "DreamArena/DreamArena.h"

void UUI_SelectRole::NativeConstruct()
{

	Super::NativeConstruct();

	DoubleSwordBtn->OnReleased.AddDynamic(this, &UUI_SelectRole::DoubleSwordBtn_Complete);

}

void UUI_SelectRole::NativeDestruct()
{
	Super::NativeDestruct();


}


void UUI_SelectRole::DoubleSwordBtn_Complete()
{
	if (ASpinArenaPlayerController* SpinArenaPlayerController =  GetOwningPlayer<ASpinArenaPlayerController>())
	{
		SpinArenaPlayerController->SpawnAndControlPawn(ERoleType::DoubleSword);
	}
	this->SetVisibility(ESlateVisibility::Collapsed);
}
