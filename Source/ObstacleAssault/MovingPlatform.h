// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(100, 100, 0);

	UPROPERTY(VisibleAnywhere, Category = "Moving Platform")
	FVector PlatformMoveDistance = FVector(0, 0, 0);

	UPROPERTY(VisibleAnywhere, Category = "Moving Platform")
	float DistanceMoved = 0.0f;

private:
	FVector startPosition;
	FVector positionOffset;
	float curvePosition;
	float targetYOffset = 3000.0f;
	float xDirection = 0.0f;
	float yDirection = 0.0f;
};
