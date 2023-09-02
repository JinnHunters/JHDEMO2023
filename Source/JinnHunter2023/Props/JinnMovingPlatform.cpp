// Fill out your copyright notice in the Description page of Project Settings.


#include "JinnMovingPlatform.h"

// Sets default values
AJinnMovingPlatform::AJinnMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJinnMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);

}

// Called every frame
void AJinnMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
	
	// Move Platform forwards
	//getcurrentlocation
	FVector CurrentLocation = GetActorLocation();
	//NOW MAKE IT MOVE add vector to that location, best to use a local variable for this
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	//set the location
	SetActorLocation(CurrentLocation);
	//Send platform back if gone to far
	// check how far we moved
	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	//reverse direction of motion if gone to far
	

	if (DistanceMoved > MoveDistanceLimit)
	{
		float OverShoot = DistanceMoved - MoveDistanceLimit;
		FString Name= GetName();
		UE_LOG(LogTemp, Display, TEXT(" %s Platform OverShoot by %f"), *Name, OverShoot);	
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistanceLimit;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	
}


void AJinnMovingPlatform:: MovePlatform(float DeltaTime)
{
// Move Platform forwards
	//getcurrentlocation
	FVector CurrentLocation = GetActorLocation();
	//NOW MAKE IT MOVE add vector to that location, best to use a local variable for this
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	//set the location
	SetActorLocation(CurrentLocation);
	//Send platform back if gone to far
	// check how far we moved
	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	//reverse direction of motion if gone to far
	

	if (ShouldPlatformReturn())
	{
		float OverShoot = DistanceMoved - MoveDistanceLimit;
		FString Name= GetName();
		UE_LOG(LogTemp, Display, TEXT(" %s Platform OverShoot by %f"), *Name, OverShoot);	
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistanceLimit;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}
//Now we are addign a rotater with a ulog to record stuff in the ulog
void AJinnMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("%s Rotating..."), *GetName());
	FRotator CurrrentRotation= GetActorRotation();
	SetActorRotation(CurrrentRotation);
	AddActorLocalRotation (RoatationVelcotiy * DeltaTime);
}

//this is a return statment to make the platform return
bool AJinnMovingPlatform::ShouldPlatformReturn() const
{
 return  GetDistanceMoved() > MoveDistanceLimit;
}

float AJinnMovingPlatform:: GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
