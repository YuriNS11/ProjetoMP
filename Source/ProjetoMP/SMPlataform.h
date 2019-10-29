// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SMPlataform.generated.h"

/**
 * 
 */
UCLASS()
class PROJETOMP_API ASMPlataform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	ASMPlataform();
		virtual void Tick(float DeltaTime) override;
		virtual void BeginPlay() override;

		UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;

		UPROPERTY(EditAnywhere)
		float SpeedPlataform = 20;

		void AddActiveTrigger();
		void RemoveActiveTrigger();

private:
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
};
