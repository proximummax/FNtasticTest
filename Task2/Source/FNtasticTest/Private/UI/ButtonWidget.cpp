// Fill out your copyright notice in the Description page of Project Settings.
#include "UI/ButtonWidget.h"
#include "Components/Button.h"


void UButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SpawnCharacterButton->OnPressed.AddUniqueDynamic(this, &ThisClass::OnButtonClicked);
}

void UButtonWidget::OnButtonClicked()
{
	OnClickedDelegate.Broadcast(this);
}