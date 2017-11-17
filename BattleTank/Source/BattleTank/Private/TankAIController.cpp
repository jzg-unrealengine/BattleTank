// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetPawn();
	auto AimTarget = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ControlledTank && !AimTarget)
	{
		UE_LOG(LogTemp, Error, TEXT("No target for AI tank %s!"), *ControlledTank->GetName());
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto AimTarget = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (AimTarget && ControlledTank)
	{
		MoveToActor(AimTarget, AcceptanceRadius);

		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(AimTarget->GetActorLocation());

		if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
			AimingComponent->Fire();
	}
}