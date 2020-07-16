// Fill out your copyright notice in the Description page of Project Settings.


#include "DieSphere.h"
#include "SphereBase.h"
#include "Engine.h"
#include "TestGameGameModeBase.h"

void ADieSphere::OnHitSphere(AActor * sphere)
{
	ATestGameGameModeBase * GameModeBase = Cast<ATestGameGameModeBase>(GetWorld()->GetAuthGameMode());
	
	GameModeBase->SetPlayerLocation();
}

