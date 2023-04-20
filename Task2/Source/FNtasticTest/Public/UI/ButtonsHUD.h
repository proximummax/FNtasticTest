// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ButtonsHUD.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTEST_API AButtonsHUD : public AHUD
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "UI")
	TSubclassOf<UUserWidget> ButtonsWidgetClass;
	
	virtual void BeginPlay() override;
};
