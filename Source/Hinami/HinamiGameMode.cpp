// Copyright Epic Games, Inc. All Rights Reserved.

#include "HinamiGameMode.h"
#include "HinamiCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHinamiGameMode::AHinamiGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void AHinamiGameMode::BeginPlay()
{
	Super::BeginPlay();
	this->ActionGameState = GetWorld()->GetGameState<AActionGameState>();
}

void AHinamiGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (ActionGameState->IsGameClear())
	{
		GameMainWidget->SetGameClearWidgetVisibility(ESlateVisibility::Visible);
	}
	
}