// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Instance = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Instance"));

}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::StartAttack()
{

}

float ABaseWeapon::CalculateTracePointDistance()
{
	return ((Instance->GetSocketTransform(FName(TEXT("TraceBegin")), RTS_Component).GetLocation() - Instance->GetSocketTransform(FName(TEXT("TraceEnd")), RTS_Component).GetLocation())).Z / TracePointCount;
}

