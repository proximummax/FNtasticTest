// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

#include "Components/AudioComponent.h"


ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	TimelineProgress.BindUFunction(this, FName("Move"));
	StartLocation = GetActorLocation();

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

	CurrentAudioComponent = UGameplayStatics::SpawnSoundAtLocation(GetWorld(), MovementSound,GetActorLocation(), FRotator::ZeroRotator,1.0f, 1.0f, 0.0f);
	SpawnFX(MoveFX);
	
		
}

void ABaseCharacter::StartTimeline()
{
	if(!CurveFloat)
		return;
	
	Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	
	Timeline.Play();
	
	CurrentAudioComponent = UGameplayStatics::SpawnSoundAtLocation(GetWorld(), SpawnSound, GetActorLocation(),FRotator::ZeroRotator ,1.0f, 1.0f, 0.0f);

	SpawnFX(SpawnedFX);
}

void ABaseCharacter::Destroy()
{
	GetWorld()->DestroyActor(this);

	CurrentAudioComponent->Stop();
	CurrentAudioComponent = UGameplayStatics::SpawnSoundAtLocation(GetWorld(), FinishedtSound,GetActorLocation(), FRotator::ZeroRotator ,1.0f, 1.0f, 0.0f);

	SpawnFX(FinishFX);
}

UNiagaraComponent* ABaseCharacter::SpawnFX(UNiagaraSystem* NiagaraSystem)
{
	
	return UNiagaraFunctionLibrary::SpawnSystemAttached(NiagaraSystem,
		this->GetRootComponent(),
		SocketName,
		FVector::ForwardVector,
		FRotator::ZeroRotator,
		EAttachLocation::SnapToTarget,
		true);
}

