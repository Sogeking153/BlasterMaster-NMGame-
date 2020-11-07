#include "Sophia.h"
#include "../Core/Coordinator.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Component/AnimationComponent.h"

extern Coordinator coordinator;
Sophia::Sophia() {
    entityID = coordinator.CreateEntity();

}

int Sophia::GetID() {
    return entityID;
}