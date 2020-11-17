#include "GoRightExteriorCommand.h"
#include "../Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/PositionComponent.h"
#include "../Component/AnimationComponent.h"
#include "../System/AnimationSystem.h"
#include "../UtilHeader.h"
#include "../HelperHeader/PlayerType.h"

void GoRightExteriorCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Go Right Exterior Command\n");
    InputContext* context = InputContext::GetInstance();

    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
    {
        Position& pos = context->coordinator->GetComponent<Position>(EntityID->jason->GetID(), ComponentType::Position);
        pos.x += JASON_WALKING_SPEED;
        EntityID->jason->SwitchState(3);
        break;
    }
    case PlayerType::SOPHIA:
        EntityID->sophia->Test();
        break;
    }
}