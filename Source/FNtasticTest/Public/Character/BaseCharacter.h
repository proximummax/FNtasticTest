// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UCurveFloat;
class UNiagaraSystem;
class UNiagaraComponent;

UCLASS()
class FNTASTICTEST_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void Move(float Value);
	
	UPROPERTY(EditAnywhere, Category= "Movement Timeline")
	UCurveFloat* CurveFloat;
	UPROPERTY(EditAnywhere, Category = "Movement Timeline")
	AActor* EndPointActor;

	void SetEndLocation(FVector EndPoint) { EndLocation = EndPoint; }
	
	void StartTimeline();
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	FTimeline Timeline;

	UPROPERTY()
	FVector EndLocation;
private:
	UPROPERTY()
	FVector StartLocation;

	void Destroy();

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* SpawnSound;
	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* MovementSound;
	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* FinishedtSound;

	UPROPERTY(EditAnywhere, Category = "VFX")
	UNiagaraSystem* SpawnedFX;
	UPROPERTY(EditAnywhere, Category = "VFX")
	UNiagaraSystem* MoveFX;
	UPROPERTY(EditAnywhere, Category = "VFX")
	UNiagaraSystem* FinishFX;
	UPROPERTY(EditAnywhere, Category = "VFX")
	FName SocketName;

	UNiagaraComponent* SpawnFX(UNiagaraSystem* NiagaraSystem);
	
};
