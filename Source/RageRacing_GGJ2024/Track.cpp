// Fill out your copyright notice in the Description page of Project Settings.


#include "Track.h"

// Sets default values
ATrack::ATrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrack::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ATrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	rotateTrack(DeltaTime, true);
	
	countTimer(DeltaTime);
}


void ATrack::countTimer(float deltaTime)
{
	timer += deltaTime;
	if (timer >= timeBetweenRotations&&positiveRotation == true)
	{
		timer = 0.0f;
		timeToRotate = true;
		positiveRotation= false;
	}else if(timer >= timeBetweenRotations&&positiveRotation == false)
	{
		timer = 0.0f;
		timeToRotate = true;
		positiveRotation = true;
	}
	
	if(positiveRotation)
		rotationAngle = 0.f;
	else
		rotationAngle = -5;
}

void ATrack::rotateTrack(float deltaTime ,bool positive)
{
	FRotator curr = GetActorRotation();
	float newPitch = FMath::FInterpTo(curr.Pitch, rotationAngle, deltaTime, 1.0f);

	SetActorRotation(FRotator(newPitch, 0.f, 0));
}


