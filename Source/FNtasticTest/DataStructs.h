#pragma once

#include "DataStructs.generated.h"

class ABaseCharacter;
class AActor;

USTRUCT(BlueprintType)
struct FUISpawnData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	FString SpawnButtonName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	TSubclassOf<ABaseCharacter> CharacterToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	FTransform SpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	FVector TargetPoint;
};
