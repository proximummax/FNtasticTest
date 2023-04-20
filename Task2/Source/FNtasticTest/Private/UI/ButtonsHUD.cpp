// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ButtonsHUD.h"

#include "Blueprint/UserWidget.h"

void AButtonsHUD::BeginPlay()
{
	Super::BeginPlay();

	if(ButtonsWidgetClass)
	{
		const auto ButtonsWidget = CreateWidget<UUserWidget>(GetWorld(), ButtonsWidgetClass);
		if(ButtonsWidget)
		{
			ButtonsWidget->AddToViewport();
		}
	}
}
