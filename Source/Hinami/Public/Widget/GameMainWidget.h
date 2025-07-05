// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameClearWidget.h"
#include "GameOverWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class HINAMI_API UGameMainWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UGameClearWidget *GameClearWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UGameOverWidget *GameOverWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock *OnHitText;

	virtual  bool Initialize()  override;
	void SetGameClearWidgetVisibility(ESlateVisibility  SlateVisibility);
	void SetGameOverWidgetVisibility(ESlateVisibility  SlateVisibility);
	void SetOnHitTextVisibility(ESlateVisibility  SlateVisibility);

};
