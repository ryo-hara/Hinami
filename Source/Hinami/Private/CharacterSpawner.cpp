// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSpawner.h"

// Sets default values
ACharacterSpawner::ACharacterSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterSpawner::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &ACharacterSpawner::SpawnCharacter, 2.0f, true);
}

// Called every frame
void ACharacterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterSpawner::SpawnCharacter()
{
	UE_LOG(LogTemp, Display, TEXT("Spawning character"));

	FTransform aTransform = FTransform(FVector(2321.0, 2160.0, 130.0));
	TObjectPtr< AActor> aActor = GetWorld()->SpawnActor<AActor>(SpawnActorClass, aTransform);
}


