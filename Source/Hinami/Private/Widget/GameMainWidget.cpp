// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameMainWidget.h"

bool UGameMainWidget::Initialize()
{
	Super::Initialize();
	GameClearWidget->SetVisibility(ESlateVisibility::Collapsed);
	return true;
}
