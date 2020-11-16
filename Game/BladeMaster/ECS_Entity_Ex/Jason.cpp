#include "Jason.h"
#include "../Core/Coordinator.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Debug.h"
Jason::Jason() {
    //entityID = coordinator.CreateEntity();

    Position pos;
    pos.x = 16;
    pos.y = 16;

    
}

int Jason::GetID() {
    return entityID;
}

void Jason::Test()
{
    DebugOut(L"This is Jason\n");
}
