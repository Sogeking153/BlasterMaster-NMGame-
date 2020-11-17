#include "AimUpcommand.h"
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

void AimUpCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Aim Up Command\n");

    InputContext* context = InputContext::GetInstance();

    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
    {
        Position& pos = context->coordinator->GetComponent<Position>(EntityID->jason->GetID(), ComponentType::Position);
        pos.y -= 1;
        EntityID->jason->SwitchState(8);
        break;
    }
    case PlayerType::SOPHIA:
        EntityID->sophia->Test();
        break;
    }
}