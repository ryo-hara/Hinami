// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomSpawnPoint.h"

#include "Hinami/HinamiCharacter.h"

// Sets default values
ARandomSpawnPoint::ARandomSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision = this->GetComponentByClass<UBoxComponent>();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ARandomSpawnPoint::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ARandomSpawnPoint::OnOverlapEnd);
}

// Called every frame
void ARandomSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ARandomSpawnPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto character = Cast<AHinamiCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("======ARandomSpawnPoint::OnOverlapBegin"));
		isPlayerEntered = true;
	}
}

void ARandomSpawnPoint::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (auto character = Cast<AHinamiCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("======ARandomSpawnPoint::OnOverlapEnd"));
		isPlayerEntered = false;
	}

}


