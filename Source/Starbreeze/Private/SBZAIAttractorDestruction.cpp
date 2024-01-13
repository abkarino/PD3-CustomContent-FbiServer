#include "SBZAIAttractorDestruction.h"
#include "Components/SceneComponent.h"
#include "SBZAIAttractorComponent.h"
#include "SBZPropDamageComponent.h"

ASBZAIAttractorDestruction::ASBZAIAttractorDestruction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SoundRange = 1500.00f;
    this->AttractorComponent = CreateDefaultSubobject<USBZAIAttractorComponent>(TEXT("SBZAIAttractorComponent"));
    this->bReplicates = true;
    FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    *p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->RootComponent->SetMobility(EComponentMobility::Static);
    this->PropDamage = CreateDefaultSubobject<USBZPropDamageComponent>(TEXT("SBZPropDamageComponent"));
}


