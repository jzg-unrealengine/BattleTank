// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Controlled = GetControlledTank();
	if (Controlled)
		UE_LOG(LogTemp, Warning, TEXT("Possessed tank: %s"), *Controlled->GetName());
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

