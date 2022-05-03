// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "NaveTerrestreEnemigo02.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER2_1SIS457_API ANaveTerrestreEnemigo02 : public ANaveTerrestre
{
	GENERATED_BODY()
	
public:
	ANaveTerrestreEnemigo02();

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
};
