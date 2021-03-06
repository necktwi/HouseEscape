// © FerryFair 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOUSEESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent (
      float DeltaTime, ELevelTick TickType,
      FActorComponentTickFunction* ThisTickFunction
   ) override;

   UPROPERTY(BlueprintAssignable) FDoorEvent OnOpen;
   UPROPERTY(BlueprintAssignable) FDoorEvent OnClose;
   
private:
   UPROPERTY(EditAnywhere)    ATriggerVolume*   PressurePlate;
   UPROPERTY(EditAnywhere)    float             DoorCloseDelay = 0.0f;
   UPROPERTY(EditAnywhere)    float             PPTriggerMass = 50.f;
   
   float    LastDoorOpenTime;
   bool     DoorOpenFlag;
   
   void  open_door();
   void  close_door();
   float get_total_mass_of_actors_on_plate();
};
