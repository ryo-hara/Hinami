// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ActionGameState.generated.h"

/**
 * 
 */
UCLASS()
class HINAMI_API AActionGameState : public AGameStateBase
{
	GENERATED_BODY()

private:
	int destroyEnemy = 0;
public:
	UFUNCTION(BlueprintCallable)
	inline void AddDestroyEnemy(){ destroyEnemy++; };

	UFUNCTION(BlueprintCallable)
	inline  bool IsGameClear(){ return destroyEnemy >= 3; }
	
};
