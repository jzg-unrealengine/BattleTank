// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;
class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation) const;
	
	/*
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurretReference(UTankTurret* TurretToSet);
	*/
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	//UPROPERTY(BlueprintReadOnly, Category = Input)
	//UTankAimingComponent* TankAimingComponent = nullptr;

	//UPROPERTY(BlueprintReadOnly, Category = Input)
	//UTankMovementComponent* TankMovementComponent = nullptr;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 20000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeSeconds = 3;

	double LastFireTime = 0;


	// Sets default values for this pawn's properties
	ATank();

};
