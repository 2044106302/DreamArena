// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_SpinArenaMain.generated.h"

class UUI_SelectRole;


UCLASS()
class DREAMARENA_API UUI_SpinArenaMain : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY( meta=(BindWidget) )
	TObjectPtr<UUI_SelectRole> SelectRole;

public:
	void ShowSelectPlayerMenu();


protected:

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;


};
