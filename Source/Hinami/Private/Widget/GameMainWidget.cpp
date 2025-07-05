// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameMainWidget.h"

bool UGameMainWidget::Initialize()
{
	Super::Initialize();
	GameClearWidget->SetVisibility(ESlateVisibility::Collapsed);
	GameOverWidget->SetVisibility(ESlateVisibility::Collapsed);
	OnHitText->SetVisibility(ESlateVisibility::Collapsed);

	return true;
}

void UGameMainWidget::SetGameClearWidgetVisibility(ESlateVisibility  SlateVisibility)
{
	GameClearWidget->SetVisibility(SlateVisibility);
}

void UGameMainWidget::SetGameOverWidgetVisibility(ESlateVisibility  SlateVisibility)
{
	GameOverWidget->SetVisibility(SlateVisibility);
}

void UGameMainWidget::SetOnHitTextVisibility(ESlateVisibility SlateVisibility)
{
	OnHitText->SetVisibility(SlateVisibility);
}
