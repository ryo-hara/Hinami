// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"

// Sets default values
ATestEnemy::ATestEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATestEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

