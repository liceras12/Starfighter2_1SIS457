// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAcuaticaEnemigo01.h"
#include "Proyectil.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ANaveAcuaticaEnemigo01::ANaveAcuaticaEnemigo01()
{

	// Movement
	MoveSpeed = 1000.0f;

	Energy = 100.0f;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;
}

void ANaveAcuaticaEnemigo01::Tick(float DeltaSeconds)
{

	const FVector FireDirection = FVector(1.0f, -1.0f, 0.f).GetClampedToMaxSize(1.0f);
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
	World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAcuaticaEnemigo01::ShotTimerExpired, FireRate);

}
void ANaveAcuaticaEnemigo01::ShotTimerExpired()
{
	bCanFire = true;
}




