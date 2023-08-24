// Fill out your copyright notice in the Description page of Project Settings.

#include "JH_FL_CPP.h"

FTimerHandle UJH_FL_CPP::PlayMontageWithCallback(ACharacter* Character, UAnimMontage* Montage, const FCallback& Callback, float& OutDuration)
{
    FTimerHandle Handle;

    // Parameter validation
    if (!IsValid(Character) || !IsValid(Montage)) return Handle;
    USkeletalMeshComponent* MeshComponent = Character->GetMesh();
    if (!IsValid(MeshComponent)) return Handle;

    // Play montage and grab its duration
    float Duration = MeshComponent->GetAnimInstance()->Montage_Play(Montage, 1.0f, EMontagePlayReturnType::Duration);
    OutDuration = Duration;
    float Rate = Character->GetWorld()->GetDeltaSeconds();

    // Bind user set Callback function to a Timer delegate
    FTimerDelegate TimerDelegate;
    TimerDelegate.BindLambda([Character, Handle, Duration, Rate, Callback]() mutable
    {
        // Execute user-defined callback if bound
        if (Callback.IsBound())
        {
            Callback.Execute();
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Callback is not bound"));
        }
    });

    // Set the timer with user defined callback
    Character->GetWorldTimerManager().SetTimer(Handle, TimerDelegate, Rate, true);

    // If the provided handle is not invalidated outside this function, it will be cleared by the following timer at the end of the montage
    FTimerHandle TempHandle;
    FTimerDelegate EndTimerCallback;
    EndTimerCallback.BindLambda([Handle, Character]() mutable {
        UE_LOG(LogTemp, Warning, TEXT("Montage ended."));
        Character->GetWorldTimerManager().ClearTimer(Handle);
    });
    Character->GetWorldTimerManager().SetTimer(TempHandle, EndTimerCallback, Duration, false);

    return Handle;
}
