// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	InputText();
	
}
void AMyActor::InputText() 
{
	GEngine->AddOnScreenDebugMessage(-1,5.0f, FColor::Blue, TEXT("hello"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

