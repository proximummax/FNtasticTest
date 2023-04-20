// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FNtasticTest/DataStructs.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTEST_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Spawn")
	TArray<FUISpawnData> SpawnDatas;
	
};
