// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YTCharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;

UCLASS()
class YT_CPP_API AYTCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AYTCharacterBase();

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	
	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category = "Player")
	UStaticMeshComponent* MeshComp;
	

protected:

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Value);
	void LookUptAtRate(float Value);

	UPROPERTY(EditAnywhere, Category = "Camera")
	float BaseTurnRate;

	UPROPERTY(EditAnywhere, Category = "Camera")
	float BaseLookUpAtRate;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
