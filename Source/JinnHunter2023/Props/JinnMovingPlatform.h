// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JinnMovingPlatform.generated.h"

UCLASS()
class JINNHUNTER2023_API AJinnMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJinnMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	private:

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
//now for roation
UPROPERTY(EditAnywhere, Category= "Roation")
FRotator RoatationVelcotiy;

//we are making a overall memeber function, our own function
void MovePlatform(float DeltaTime);
void RotatePlatform(float DeltaTime);

bool ShouldPlatformReturn() const;
float GetDistanceMoved() const;
};
