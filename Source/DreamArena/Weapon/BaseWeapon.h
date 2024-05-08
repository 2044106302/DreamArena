// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class DREAMARENA_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> Instance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void StartAttack();

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 TracePointCount;


	/*
	* Only one Property is added here for future expansion
	*/
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Property")
	int32 Damage;


	float CalculateTracePointDistance();


	 

};
