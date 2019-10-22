// Fill out your copyright notice in the Description page of Project Settings.


#include "SMPlataform.h"

ASMPlataform::ASMPlataform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}
void ASMPlataform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();

		Location += FVector(DeltaTime * SpeedPlataform, 0, 0);

		SetActorLocation(Location); 
	}
}
