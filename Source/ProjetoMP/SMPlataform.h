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

		UPROPERTY(EditAnywhere)
		float SpeedPlataform = 20;
	
};
