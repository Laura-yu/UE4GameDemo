// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereBase.h"
#include "Components/InputComponent.h"
#include "Engine.h"

// Sets default values
ASphereBase::ASphereBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsInput = true;
	SphereSpeed = 150.0f;
	SpeedMin = SphereSpeed;
	SpeedMax = 300.0f;

	SphereMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpherebaseComp"));
	SphereMeshComp->SetSimulatePhysics(true);

	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArmComp"));
	CameraArmComp->SetupAttachment(SphereMeshComp);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(CameraArmComp);
}

// Called when the game starts or when spawned
void ASphereBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASphereBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(IsInput && AngularVector != FVector(0, 0, 0))
		SphereMeshComp->SetPhysicsAngularVelocity(AngularVector);

}

// Called to bind functionality to input
void ASphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASphereBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASphereBase::MoveRight);

	PlayerInputComponent->BindAction("SpeedUp", IE_Pressed, this, &ASphereBase::SpeedUp);
	PlayerInputComponent->BindAction("SpeedUp", IE_Released, this, &ASphereBase::SpeedLow);

}

void ASphereBase::MoveForward(float val)
{
	
	if (IsInput) 
	{
		AngularVector.Y = SphereSpeed * val;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "go up/down");
		if (SphereSpeed == 200.0) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Speed: 200");
		}
		else if (SphereSpeed == 350.0) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Speed: 350");
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Speed: changing");
		}
	}

}

void ASphereBase::MoveRight(float val)
{
	
	if (IsInput)
	{
		AngularVector.X = SphereSpeed * val;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "go right/left");
		if (SphereSpeed == 200.0) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Speed: 200");
		}
		else if (SphereSpeed == 350.0) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Speed: 350");
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Speed: changing");
		}
	}
}

void ASphereBase::SpeedUp()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,"Speed up");
	SphereSpeed = SpeedMax;
}

void ASphereBase::SpeedLow()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "Speed down");
	SphereSpeed = SpeedMin;
}