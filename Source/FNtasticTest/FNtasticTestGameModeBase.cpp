// Copyright Epic Games, Inc. All Rights Reserved.


#include "FNtasticTestGameModeBase.h"

#include "UI/ButtonsHUD.h"
#include "InputPlayerController.h"

AFNtasticTestGameModeBase::AFNtasticTestGameModeBase()
{
	PlayerControllerClass = AInputPlayerController::StaticClass();
	HUDClass = AButtonsHUD::StaticClass();
}
