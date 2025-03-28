// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PoseableMeshComponent.h"  // Include PoseableMeshComponent
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to move the model based on pose keypoints
	void MoveModelWithPoseData(const TArray<FVector>& Keypoints);

private:
	UPROPERTY(VisibleAnywhere)
	UPoseableMeshComponent* PoseableMeshComponent;

	// Example keypoints for different bones
	FVector RootPosition;
	FVector HeadPosition;
	FVector HandRightPosition;
	FVector HandLeftPosition;
	FVector FootRightPosition;
	FVector FootLeftPosition;

};
