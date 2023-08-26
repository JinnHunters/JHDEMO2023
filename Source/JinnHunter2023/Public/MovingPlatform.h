// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class JINNHUNTER2023_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

// Speed of the Platform by untis assigned to unreal X,Y and Z
	UPROPERTY(EditAnywhere, Category="Moving Platform")

	FVector PlatformVelocity = FVector(100, 0, 0);

//Determine Start Variable
	UPROPERTY(EditAnywhere)
	FVector StartLocation;

//Determine Distance Moved 
	UPROPERTY(EditAnywhere)
	float DistanceMoved ;

//Determine Limit of Object Movement
	UPROPERTY(EditAnywhere, Category = " Limit")
	float MoveDistanceLimit = 100;  

};