// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "NaveTerrestreEnemigo01.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER2_1SIS457_API ANaveTerrestreEnemigo01 : public ANaveTerrestre
{
	GENERATED_BODY()
	
public:
	ANaveTerrestreEnemigo01();

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
};
