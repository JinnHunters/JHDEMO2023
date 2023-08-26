// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();


	
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
// Move Platform forwards
	//getcurrentlocation
FVector CurrentLocation = GetActorLocation();
	//add vector to that location, best to use a local variable for this
CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	//set the location
SetActorLocation(CurrentLocation);
//Send platform back if gone to far
	// check how far we moved
	DistanceMoved = FVector ::Dist(StartLocation, CurrentLocation);
	//reverse direction of motion if gone to far
	

	if (DistanceMoved > MoveDistanceLimit)
	{
		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistanceLimit;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	
}



