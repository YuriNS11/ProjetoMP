// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaTrigger.h"
#include "Components/BoxComponent.h"
#include "SMPlataform.h"
// Sets default values
APlataformaTrigger::APlataformaTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlataformaTrigger::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlataformaTrigger::OnOverlapEnd);

}

// Called when the game starts or when spawned
void APlataformaTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataformaTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlataformaTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (ASMPlataform* Plataform : PlataformsTriggers)
	{
		Plataform->AddActiveTrigger();
	}
}

void APlataformaTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	for (ASMPlataform* Plataform : PlataformsTriggers)
	{
		Plataform->RemoveActiveTrigger();
	}
}

