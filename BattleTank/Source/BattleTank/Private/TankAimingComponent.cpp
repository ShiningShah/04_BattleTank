// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "./Public/TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}




// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{

	if (!Barrel) { return; }
	FVector OutLuanchVelocity;
	
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if(UGameplayStatics::SuggestProjectileVelocity(
			this, 
			OutLuanchVelocity, 
			StartLocation, 
			HitLocation, 
			LaunchSpeed,  
			ESuggestProjVelocityTraceOption::DoNotTrace)
			)
	{

		auto AimDirection = OutLuanchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);

	}
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

}