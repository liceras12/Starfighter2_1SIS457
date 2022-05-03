// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaEnemigo02.h"
#include "Proyectil.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ANaveAereaEnemigo02::ANaveAereaEnemigo02()
{

	// Movement
	MoveSpeed = 1000.0f;

	Energy = 100.0f;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;
}

void ANaveAereaEnemigo02::Tick(float DeltaSeconds)
{

	const FVector FireDirection = FVector(0.0f, 10.0f, 0.f).GetClampedToMaxSize(1.0f);
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
	World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaEnemigo02::ShotTimerExpired, FireRate);

}
void ANaveAereaEnemigo02::ShotTimerExpired()
{
	bCanFire = true;
}



