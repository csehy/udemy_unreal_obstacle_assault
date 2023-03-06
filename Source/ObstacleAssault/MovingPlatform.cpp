// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#define _USE_MATH_DEFINES 1
#include <math.h>

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

    startPosition = GetActorLocation();
    positionOffset = FVector::ZeroVector;
    yDirection = 1.0f;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    const float cycleTime = M_PI * 2;       // time to complete one sine wave (in seconds)
    float cycleSpeed = M_PI * 2 / cycleTime;
    FVector deltaMove = FVector::ZeroVector;

    // Move platform forward
    curvePosition += DeltaTime * cycleSpeed;
    if (curvePosition >= M_PI * 2)
    {
        curvePosition -= M_PI * 2;
    }

    float xMove = sin(curvePosition) * PlatformVelocity.X;
    deltaMove.X = abs(xMove);

    float yMove = positionOffset.Y + PlatformVelocity.Y * DeltaTime * yDirection;
    deltaMove.Y = abs(yMove);
    if (yMove >= targetYOffset)
    {
        float adjustment = yMove - targetYOffset;
        yMove = yMove - adjustment * 2;
        yDirection = -1.0f;
    }
    else if (yMove <= 0.0f)
    {
        yMove = -yMove;
        yDirection = 1.0f;
    }

    positionOffset.X = xMove;
    positionOffset.Y = yMove;
    SetActorLocation(startPosition + positionOffset);

    PlatformMoveDistance = GetActorLocation() - startPosition;
    DistanceMoved += FVector::Distance(FVector::ZeroVector, deltaMove);
}

