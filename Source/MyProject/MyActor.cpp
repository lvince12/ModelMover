// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/PoseableMeshComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the PoseableMeshComponent
	PoseableMeshComponent = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("PoseableMesh"));
	RootComponent = PoseableMeshComponent;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// Example setup - these could be dynamic in a real scenario
	RootPosition = FVector(0, 0, 40);
	HeadPosition = FVector(0, 0, 180);
	HandRightPosition = FVector(50, -30, 100);
	HandLeftPosition = FVector(-50, 30, 100);
	FootRightPosition = FVector(20, -20, 0);
	FootLeftPosition = FVector(-20, 20, 0);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Here we will update the actor's pose based on keypoints
	MoveModelWithPoseData({ RootPosition, HeadPosition, HandRightPosition, HandLeftPosition, FootRightPosition, FootLeftPosition });
}

void AMyActor::MoveModelWithPoseData(const TArray<FVector>& Keypoints)
{
	if (Keypoints.Num() < 6) return;  // Ensure we have enough keypoints

	// Move specific bones using PoseableMeshComponent
	PoseableMeshComponent->SetBoneLocationByName("head", Keypoints[1], EBoneSpaces::WorldSpace);
	PoseableMeshComponent->SetBoneLocationByName("hand_r", Keypoints[2], EBoneSpaces::WorldSpace);
	PoseableMeshComponent->SetBoneLocationByName("hand_l", Keypoints[3], EBoneSpaces::WorldSpace);
	PoseableMeshComponent->SetBoneLocationByName("foot_r", Keypoints[4], EBoneSpaces::WorldSpace);
	PoseableMeshComponent->SetBoneLocationByName("foot_l", Keypoints[5], EBoneSpaces::WorldSpace);

	// Debugging - Draw spheres at keypoints
	for (const FVector& Point : Keypoints)
	{
		DrawDebugSphere(GetWorld(), Point, 5.0f, 12, FColor::Red, false, 1.0f);
	}
}

