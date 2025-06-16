// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestEnemy.generated.h"

UCLASS()
class HINAMI_API ATestEnemy : public ACharacter
{
	GENERATED_BODY()

	     UPROPERTY(EditAnywhere)
         int32 CountdownTime;


public:

	UPROPERTY(EditAnywhere)
	int32 HP;

	ATestEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
