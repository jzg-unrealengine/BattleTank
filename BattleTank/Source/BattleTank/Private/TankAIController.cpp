// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"



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

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PoseessedTank = Cast<ATank>(InPawn);
		if (!ensure(PoseessedTank)) { return; }

		PoseessedTank->OnTankDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::OnTankDeath()
{
	GetPawn()->DetachFromControllerPendingDestroy();
}