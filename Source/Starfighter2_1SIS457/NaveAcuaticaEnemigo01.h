// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAcuatica.h"
#include "NaveAcuaticaEnemigo01.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER2_1SIS457_API ANaveAcuaticaEnemigo01 : public ANaveAcuatica
{
	GENERATED_BODY()
	
public:
	ANaveAcuaticaEnemigo01();

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;
};
