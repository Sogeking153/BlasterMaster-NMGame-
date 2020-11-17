#include "LayDownCommand.h"
//For testing purpose
#include "../Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/PositionComponent.h"
#include "../Component/AnimationComponent.h"
#include "../System/AnimationSystem.h"
#include "../UtilHeader.h"
#include "../HelperHeader/PlayerType.h"

void LayDownCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Lay Down Command\n");
    InputContext* context = InputContext::GetInstance();

    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
    {
        Position& pos = context->coordinator->GetComponent<Position>(EntityID->jason->GetID(), ComponentType::Position);
        pos.y += 1;
        EntityID->jason->SwitchState(4);
        break;
    }
    case PlayerType::SOPHIA:
        EntityID->sophia->Test();
        break;
    }
}