// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RandomSpawnPoint.h"
#include "GameFramework/Actor.h"
#include "CharacterSpawner.generated.h"

class ARandomSpawnPoint;

UCLASS()
class HINAMI_API ACharacterSpawner : public AActor
{
	GENERATED_BODY()

	// ここでプレイヤーの当たってない当たり判定内にエネミーを入れる処理を置く
public:	
	ACharacterSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyActors")
	TArray<ARandomSpawnPoint*> RandomSpawnPoints;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnActorClass;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	void SpawnCharacter();
};
