// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ButtonsWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Character/BaseCharacter.h"
#include "Components/Button.h"
#include "CustomGameInstance.h"


void UButtonsWidget::NativeOnInitialized()
{
	
	Super::NativeOnInitialized();
	
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(),Buttons,UButtonWidget::StaticClass(),false );
	for (auto Button : Buttons)
	{
		const auto ButtonWidget = Cast<UButtonWidget>(Button);
		ButtonWidget->OnClickedDelegate.AddUniqueDynamic(this, &ThisClass::SpawnCharacter);
	}

}


void UButtonsWidget::SpawnCharacter(UButtonWidget* Button)
{
	GameInstance = GetWorld()->GetGameInstance<UCustomGameInstance>();

	auto j = Button->GetName();
	for (auto SpawnData : GameInstance->SpawnDatas)
	{
		if (!SpawnData.SpawnButtonName.Equals(Button->GetName()))
			continue;

		ABaseCharacter* Character = GetWorld()->SpawnActor<ABaseCharacter>(SpawnData.CharacterToSpawn, SpawnData.SpawnTransform.GetLocation(), SpawnData.SpawnTransform.GetRotation().Rotator());
		if (Character)
		{
			Character->SetEndLocation(SpawnData.TargetPoint);
			Character->StartTimeline();
		}
	}

}

