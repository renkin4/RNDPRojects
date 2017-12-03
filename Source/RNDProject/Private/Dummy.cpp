// Fill out your copyright notice in the Description page of Project Settings.

#include "Dummy.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


// Sets default values
ADummy::ADummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	RootComponent = Mesh;

	bReplicates = true;
}

// Called when the game starts or when spawned
void ADummy::BeginPlay()
{
	Super::BeginPlay();
	/*PrintHello();*/
}

void ADummy::SERVER_PrintHello_Implementation()
{
	PrintHello();
}

bool ADummy::SERVER_PrintHello_Validate()
{
	return true;
}

void ADummy::PrintHello()
{
	GEngine->AddOnScreenDebugMessage(-1, 123.f, FColor::Green, TEXT("Client Server Hello"));
	if (Role < ROLE_Authority) 
	{
		SERVER_PrintHello();
		return;
	}
	Mesh->SetWorldLocation(FVector(0.0f, 0.0f, 1000.0f));

	GEngine->AddOnScreenDebugMessage(-1, 123.f, FColor::Red, TEXT("SERVER Hello"));

}

// Called every frame
void ADummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

