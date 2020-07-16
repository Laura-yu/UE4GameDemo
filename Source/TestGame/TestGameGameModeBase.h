// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME_API ATestGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		ATestGameGameModeBase();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayPawn")
		class ASphereBase * PlayPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CurrentStart")
		FVector CurrentStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsEnd;

public:
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

public:
	void SetPlayerLocation();
	void SetPlayerLocation(FVector Start);

	void SetPlayerInput(bool isInput);
	void SetCurrentStart(FVector Location);
};
