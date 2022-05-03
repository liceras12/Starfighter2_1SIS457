// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaEnemigo01.h"
#include "Proyectil.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ANaveAereaEnemigo01::ANaveAereaEnemigo01()
{

	// Movement
	MoveSpeed = 1000.0f;

	Energy = 100.0f;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;
}

void ANaveAereaEnemigo01::Tick(float DeltaSeconds)
{
	//const float ForwardValue = 1 ;
	//const float RightValue = GetInputAxisValue(MoveRightBinding);

	/*if (ForwardValue != 0.0f || RightValue != 0.0f) {

		if (ForwardValue != FireForwardValue) {
			FireForwardValue = ForwardValue;
		}

		if (RightValue != FireRightValue) {
			FireRightValue = RightValue;
		}
	}*/

	//UE_LOG(LogTemp, Warning, TEXT("ForwardValue: %f RightValue: %f"), ForwardValue, RightValue);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	
	const FVector MoveDirection = FVector(-0.20f, 0.0f, 0.f);

	
	

	
	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		//RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		/*
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}*/
	}

	const FVector FireDirection = FVector(-1.0f, 0.0f, 0.f).GetClampedToMaxSize(1.0f);
	//const FVector FireDirection = GetActorLocation();
	// Try and fire a shot
	//FireShot(FireDirection);

	bCanFire = true;
	const FRotator FireRotation = FireDirection.Rotation();
	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
		//UE_LOG(LogTemp, Warning, TEXT("SpawnLocation(X, Y) = %s, %s FireRotation(X, Y) =  s, s"), SpawnLocation.X, SpawnLocation.Y);
		//UE_LOG(LogTemp, Warning, TEXT("World not nullptr"));
	}

	//bCanFire = false;
	World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaEnemigo01::ShotTimerExpired, FireRate);

}

void ANaveAereaEnemigo01::Fire() {
	bCanFire = true;
	/*UE_LOG(LogTemp, Warning, TEXT("Se presiono la barra espaciadora"));
	// Create fire direction vector

	UE_LOG(LogTemp, Warning, TEXT("FireForwardValue: %f FireRightValue: %f"), FireForwardValue, FireRightValue);
	*/
	const FVector FireDirection = FVector(0.0f, 1.0f, 0.f);
	//const FVector FireDirection = GetActorLocation();
	// Try and fire a shot
	FireShot(FireDirection);
}

void ANaveAereaEnemigo01::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{

		// If we are pressing fire stick in a direction
		//if (FireDirection.SizeSquared() > 0.0f)
		//{
		const FRotator FireRotation = FireDirection.Rotation();
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			//UE_LOG(LogTemp, Warning, TEXT("SpawnLocation(X, Y) = %s, %s FireRotation(X, Y) =  s, s"), SpawnLocation.X, SpawnLocation.Y);
			//UE_LOG(LogTemp, Warning, TEXT("World not nullptr"));
		}

		//bCanFire = false;
		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaEnemigo01::ShotTimerExpired, FireRate);

		// try and play the sound if specified

	/*	if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}*/

		bCanFire = false;
		//}
	}
}

void ANaveAereaEnemigo01::ShotTimerExpired()
{
	bCanFire = true;
}