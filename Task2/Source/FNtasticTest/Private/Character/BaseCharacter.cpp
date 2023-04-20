// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>


ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this, FName("Move"));

		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
		StartLocation = GetActorLocation();
		
	}
}
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);

	if (!Timeline.IsPlaying())
		Destroy();
}
void ABaseCharacter::Move(float Value)
{
	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Value);
	SetActorLocation(NewLocation);

	UGameplayStatics::PlaySound2D(GetWorld(), MovementSound, 1.0f, 1.0f, 0.0f);
	SpawnFX(MoveFX);
}

void ABaseCharacter::StartTimeline()
{
	Timeline.Play();
	
	UGameplayStatics::PlaySound2D(GetWorld(), SpawnSound, 1.0f, 1.0f, 0.0f);
	SpawnFX(SpawnedFX);
}

void ABaseCharacter::Destroy()
{
	GetWorld()->DestroyActor(this);

	UGameplayStatics::PlaySound2D(GetWorld(), FinishedtSound, 1.0f, 1.0f, 0.0f);
	SpawnFX(FinishFX);
}

UNiagaraComponent* ABaseCharacter::SpawnFX(UNiagaraSystem* NiagaraSystem)
{

	return UNiagaraFunctionLibrary::SpawnSystemAttached(NiagaraSystem,
		this->GetRootComponent(),
		SocketName,
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		EAttachLocation::SnapToTarget,
		true);
}

