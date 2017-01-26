// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Public/Tank.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
public:

	void BeginPlay() override;
	ATank* GetControlledTank() const;
	
	ATank* GetPlayerTank() const;
	
};
