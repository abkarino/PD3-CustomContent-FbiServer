#include "SBZAgilityQueryParams.h"

USBZAgilityQueryParams::USBZAgilityQueryParams() {
    this->Radius = 34.00f;
    this->ObstacleDetectionProfileName = TEXT("Pawn");
    FProperty* p_NativeClass = GetClass()->FindPropertyByName("NativeClass");
    *p_NativeClass->ContainerPtrToValuePtr<UClass*>(this) = USBZAgilityQueryParams::StaticClass();
}


