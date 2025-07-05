// Copyright Epic Games, Inc. All Rights Reserved.

#include "HinamiGameMode.h"
#include "HinamiCharacter.h"
#include "Kismet/GameplayStatics.h"
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

	mainCharacter = Cast<AHinamiCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	mainCharacter->OnStateChanged.BindLambda([this](MainCharacterState state)
	{
		this->OnMainCharacterStateChanged(state);
	});
	
}

void AHinamiGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (ActionGameState->IsGameClear())
	{
		GameMainWidget->SetGameClearWidgetVisibility(ESlateVisibility::Visible);
	}
	
}

void AHinamiGameMode::OnMainCharacterStateChanged(MainCharacterState state)
{
	switch (state)
	{
	case invincible:
		this->GameMainWidget->SetOnHitTextVisibility(ESlateVisibility::Visible);
		break;
	case Idle:
		this->GameMainWidget->SetGameOverWidgetVisibility(ESlateVisibility::Collapsed);
		this->GameMainWidget->SetOnHitTextVisibility(ESlateVisibility::Collapsed);
		UE_LOG(LogTemp, Warning, TEXT("======MainCharacterState::Idle"));
		break;
	case Death:
		this->GameMainWidget->SetGameOverWidgetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Warning, TEXT("======MainCharacterState::Death"));
		break;
	}
}
