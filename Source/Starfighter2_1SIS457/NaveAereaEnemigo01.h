// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaEnemigo01.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER2_1SIS457_API ANaveAereaEnemigo01 : public ANaveAerea
{
	GENERATED_BODY()
	
public:
	ANaveAereaEnemigo01();

		virtual void BeginPlay() override;
		// Begin Actor Interface
		virtual void Tick(float DeltaSeconds) override;
		

		void Fire();

		/* Fire a shot in the specified direction */
		void FireShot(FVector FireDirection);

		/* Handler for the fire timer expiry */
		void ShotTimerExpired();

		/** Offset from the ships location to spawn projectiles */
		UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
			FVector GunOffset;

		/* How fast the weapon will fire */
		UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
			float FireRate;

		UPROPERTY(EditAnywhere)
			class UBoxComponent* DamageCollision;

		//AI del enemigo
		UPROPERTY(VisibleDefaultsOnly, Category = enemy)
			class UAIPerceptionComponent* AIPerComp;

		UPROPERTY(VisibleDefaultsOnly, Category = enemy)
			class UAISenseConfig_Sight* SightConfig;

		UFUNCTION()
			void OnSensed(const TArray<AActor*>& UpdatedActors);

		UPROPERTY(VisibleAnywhere, Category = Movement)
			FRotator EnemyRotation;

		UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Movement)
			FRotator CurrentVelocity;

		UPROPERTY(VisibleAnywhere, Category = Movement)
			FRotator BaseLocation;

		void SetNewRotation(FVector TargetPosition, FVector CurrentPosition);


private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

};
