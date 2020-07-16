// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework\SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SphereBase.generated.h"

UCLASS()
class TESTGAME_API ASphereBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASphereBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereMeshComp")
		UStaticMeshComponent * SphereMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraArmComp")
		USpringArmComponent * CameraArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraComp")
		UCameraComponent * CameraComp;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SphereSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SpeedMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SpeedMax;


	FVector AngularVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float val);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float val);

	UFUNCTION(BlueprintCallable)
		void SpeedUp();

	UFUNCTION(BlueprintCallable)
		void SpeedLow();
};
