// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "TestGameGameModeBase.h"
#include "Engine.h"
#include "SphereBase.h"

ATestGameGameModeBase::ATestGameGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	IsEnd = false;
}

void ATestGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ASphereBase * Pawn = Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Pawn)
	{
		PlayPawn = Pawn;
		CurrentStart = PlayPawn->GetActorLocation();
	}

}

void ATestGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATestGameGameModeBase::SetPlayerLocation()
{
	PlayPawn->SetActorLocation(CurrentStart);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}

void ATestGameGameModeBase::SetPlayerLocation(FVector Start)
{
	PlayPawn->SetActorLocation(Start);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}

void ATestGameGameModeBase::SetCurrentStart(FVector Location)
{
	if (Location != FVector(0, 0, 0))
	{
		CurrentStart = Location;
	}
}

void ATestGameGameModeBase::SetPlayerInput(bool isInput)
{
	PlayPawn->IsInput = isInput;
	if (!isInput)
	{
		IsEnd = true;
	}
}