// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveLocation.h"
#include "TestGameGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ASaveLocation::ASaveLocation()
{
	SaveMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMesh"));
	HitBoxComp->SetupAttachment(SaveMeshComp);
}

void ASaveLocation::OnHitSphere(AActor * sphere)
{
	ATestGameGameModeBase * GameModeBase = Cast<ATestGameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetCurrentStart(HitBoxComp->GetComponentLocation());
}