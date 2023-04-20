// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBUIOnClickedSignature, class UButtonWidget*, Button);
UCLASS()
class FNTASTICTEST_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()

	

public:
	
	FBUIOnClickedSignature OnClickedDelegate;
protected:
	virtual void NativeConstruct() override;

	// In the Blueprint subclass, make sure you create aButton called "MainButton"
	UPROPERTY(meta=(BindWidget))
	class UButton* SpawnCharacterButton;
	
	UFUNCTION()
	void OnButtonClicked();
};
