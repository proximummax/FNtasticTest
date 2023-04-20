// Fill out your copyright notice in the Description page of Project Settings.


#include "InputPlayerController.h"

#include "CustomGameInstance.h"
#include "Blueprint/UserWidget.h"

void AInputPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}
