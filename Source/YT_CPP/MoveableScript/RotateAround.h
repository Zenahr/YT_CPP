// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateAround.generated.h"

UCLASS()
class YT_CPP_API ARotateAround : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotateAround();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float AngleAxis;

	UPROPERTY(EditAnywhere, Category = "ZenRotate")
		AActor* TargetActor;

	UPROPERTY(EditAnywhere, Category = "ZenRotate")
		FVector Dimensions;

	UPROPERTY(EditAnywhere, Category = "ZenRotate")
		FVector AxisVector;

	UPROPERTY(EditAnywhere, Category = "ZenRotate")
		float Multiplier;
};
