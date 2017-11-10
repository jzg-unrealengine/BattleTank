// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//FMath::Clamp<float>(Throttle, -1, 1);
	
	//UE_LOG(LogTemp, Error, TEXT("%s speed: %f"), *GetOwner()->GetName(), Throttle);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankBody = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankBody->AddForceAtLocation(ForceApplied, ForceLocation);
}

