// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JH_FL_CPP.generated.h"

DECLARE_DYNAMIC_DELEGATE(FCallback);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class JINNHUNTER2023_API UJH_FL_CPP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FTimerHandle PlayMontageWithCallback(ACharacter* Character, UAnimMontage* Montage, const FCallback& Callback, float& OutDuration);

};
