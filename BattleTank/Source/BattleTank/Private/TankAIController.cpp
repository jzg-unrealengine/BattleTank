// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Controlled = GetControlledTank();
	ATank* AimTarget = GetPlayerTank();
	if (Controlled && !AimTarget)
	{
		UE_LOG(LogTemp, Error, TEXT("No target for AI tank %s!"), *Controlled->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
