// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "../Public/TankAiController.h"


void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	//UE_LOG(LogTemp, Warning, TEXT("AI controller is possissing : %s"), *ControlledTank->GetName());

	auto PlayerTank = GetPlayerTank();

	if (ControlledTank)
	{
		if (PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("AI controller %s sees player conroller %s"), *ControlledTank->GetName(), *PlayerTank->GetName());
		}

		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AI controller %s did not find Player Tank"));
		}
	}
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);

}


