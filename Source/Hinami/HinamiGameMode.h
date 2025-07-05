// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActionGameState.h"
#include "GameFramework/GameModeBase.h"
#include "Widget/GameMainWidget.h"
#include "HinamiCharacter.h"
#include "HinamiGameMode.generated.h"

UCLASS(minimalapi)
class AHinamiGameMode : public AGameModeBase
{
	GENERATED_BODY()
private:
	UGameMainWidget* GameMainWidget;
	AActionGameState* ActionGameState;
	AHinamiCharacter *mainCharacter;

public:
	AHinamiGameMode();

	UFUNCTION(BlueprintCallable)
	void SetGameMainWidget(UGameMainWidget* gameMainWidget)
	{
		this->GameMainWidget = gameMainWidget;
	};

	void Tick(float DeltaSeconds) override;
	void BeginPlay() override;

private:
	void OnMainCharacterStateChanged(MainCharacterState state);
};



