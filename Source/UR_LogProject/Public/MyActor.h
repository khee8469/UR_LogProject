// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UR_LOGPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
private:
	FVector2D start;
	FVector2D end;
	int32 evCnt;
	float totDist;
	float dist;

public:	
	AMyActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	float Distance(FVector2D first, FVector2D second);
	void Move();
	int32 Step();
	int32 CreateEvent();
};
