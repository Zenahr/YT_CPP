// Fill out your copyright notice in the Description page of Project Settings.


#include "YTCharacterBase.h"
#include "GameFramework\SpringArmComponent.h"
#include "Camera\CameraComponent.h"
#include "Components\StaticMeshComponent.h"
#include "Components\InputComponent.h"
#include "GameFramework\Controller.h"

// Sets default values
// Constructor
AYTCharacterBase::AYTCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	MeshComp->SetupAttachment(RootComponent);

	BaseTurnRate = 45.0f;
	BaseLookUpAtRate = 45.5f;
}


void AYTCharacterBase::MoveForward(float Value)
{

}

void AYTCharacterBase::MoveRight(float Value)
{

}

void AYTCharacterBase::TurnAtRate(float Value)
{

}

void AYTCharacterBase::LookUptAtRate(float Value)
{

}


// Called to bind functionality to input
void AYTCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveForward", this, &AYTCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AYTCharacterBase::MoveRight);
	
	// Mouse input
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	// Controller input
	PlayerInputComponent->BindAxis("TurnRate", this, &AYTCharacterBase::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AYTCharacterBase::LookUptAtRate);

}

