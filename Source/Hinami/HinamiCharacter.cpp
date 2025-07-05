// Copyright Epic Games, Inc. All Rights Reserved.

#include "HinamiCharacter.h"
#include "HinamiProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "TestEnemy.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AHinamiCharacter

AHinamiCharacter::AHinamiCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

//////////////////////////////////////////////////////////////////////////// Input

void AHinamiCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AHinamiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		this->enhancedInputComponent = EnhancedInputComponent;
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHinamiCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHinamiCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AHinamiCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AHinamiCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AHinamiCharacter::SetCollisionDetection()
{
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AHinamiCharacter::OnHit);
}

void AHinamiCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (isInvincible)
	{
		return;
	}

	if (auto enemy = Cast<ATestEnemy>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("======HitEnemy"));
		OnHitEnemy();
	}
	
}

void AHinamiCharacter::OnHitEnemy()
{
	this->hitTimestamp = FDateTime::Now();
	isInvincible = true;
	hp--;
	if (hp <= 0)
	{
		OnStateChanged.Execute(MainCharacterState::Death);
		isDeath = true;
		enhancedInputComponent->ClearActionEventBindings();
		// 移動をキル
	}else
	{
		OnStateChanged.Execute(MainCharacterState::invincible);
	}
	// ダメージ処理を入れる
}


void AHinamiCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetCollisionDetection();
}

void AHinamiCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (isInvincible && !isDeath && !isClear)
	{
		auto pastTime = FDateTime::Now() - hitTimestamp;
		if (pastTime.GetSeconds() >= INVINCIBLE_SECOND)
		{
			isInvincible = false;
			OnStateChanged.Execute(MainCharacterState::Idle);
		}
	}
}

void AHinamiCharacter::SetClearInvincible()
{
	OnStateChanged.Execute(MainCharacterState::ClearInvincible);
	isClear = true;
	isInvincible = true;
}
