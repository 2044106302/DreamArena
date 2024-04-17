// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SpinArenaMain.h"
#include "UI_SelectRole.h"

void UUI_SpinArenaMain::ShowSelectPlayerMenu()
{
	SelectRole->SetVisibility(ESlateVisibility::Visible);
}

void UUI_SpinArenaMain::NativeConstruct()
{
	Super::NativeConstruct();

	SelectRole->SetVisibility(ESlateVisibility::Collapsed);

}

void UUI_SpinArenaMain::NativeDestruct()
{
	Super::NativeDestruct();



}
