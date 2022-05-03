// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestreEnemigo02.h"

#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ANaveTerrestreEnemigo02::ANaveTerrestreEnemigo02()
{

	// Movement
	MoveSpeed = 1000.0f;

	Energy = 100.0f;


}

void ANaveTerrestreEnemigo02::Tick(float DeltaSeconds)
{

	const FVector MoveDirection = FVector( -0.2f, 0.0f, 0.f);


	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		/*
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}*/
	}

}
