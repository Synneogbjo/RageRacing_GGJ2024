// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Track.generated.h"

UCLASS()
class RAGERACING_GGJ2024_API ATrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void countTimer(float deltaTime);
	UFUNCTION()
	void rotateTrack(float deltaTime, bool positive);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool timeToRotate = false;
	float timer = 0.0f;
	UPROPERTY(EditAnywhere)
	float timeBetweenRotations = 10.0f;
	uint8 amoutOfRotation = 0;
	float rotationAngle = 20.f;
	bool positiveRotation = true;
	
};
