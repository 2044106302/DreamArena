// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinBody.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASpinBody::ASpinBody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RotateY = 0.0f;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(BoxCollision);

}

// Called when the game starts or when spawned
void ASpinBody::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpinBody::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateY += RotateRate;
	SetActorRotation(FRotator(0, RotateY, 0));


}

