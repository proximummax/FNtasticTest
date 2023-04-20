// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ButtonWidget.h"
#include "CustomGameInstance.h"
#include "Blueprint/UserWidget.h"

#include "ButtonsWidget.generated.h"


UCLASS()
class FNTASTICTEST_API UButtonsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	TArray<UUserWidget*> Buttons;
	virtual void NativeOnInitialized() override;

	UPROPERTY()
	UCustomGameInstance* GameInstance;
private:

	UFUNCTION()
	void SpawnCharacter(UButtonWidget* Button);

};
