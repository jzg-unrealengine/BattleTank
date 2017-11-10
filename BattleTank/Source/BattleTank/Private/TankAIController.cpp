// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "Engine/World.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = Cast<ATank>(GetPawn());
	AimTarget = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (ControlledTank && !AimTarget)
	{
		UE_LOG(LogTemp, Error, TEXT("No target for AI tank %s!"), *ControlledTank->GetName());
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AimTarget && ControlledTank)
	{
		ControlledTank->AimAt(AimTarget->GetActorLocation());

		//TODO Inspect that target is already being aimed at (don't waste ammo shooting in clearly wrong direction)
		ControlledTank->Fire();
	}
}