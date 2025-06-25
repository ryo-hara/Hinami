// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameClearWidget.h"
#include "Blueprint/UserWidget.h"
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

	virtual  bool Initialize()  override;
};
