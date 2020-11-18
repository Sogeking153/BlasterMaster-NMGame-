#include "LayDownCommand.h"
#include "../HelperHeader/Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../Component/AnimationComponent.h"
#include "../System/AnimationSystem.h"
#include "../HelperHeader/UtilHeader.h"
#include "../HelperHeader/PlayerType.h"

void LayDownCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Lay Down Command\n");
    InputContext* context = InputContext::GetInstance();

    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
    {
        switch (currentKeyEventType)
        {
        case Command::Hold:
            break;
        case Command::KeyDown:
        {
            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
            velocity.vx = 0;
            Direction& dir = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
            
            if (EntityID->jason->currentState == Jason::Idle_Left)
                EntityID->jason->SwitchState(Jason::Crawl_Idle_Left);
            else EntityID->jason->SwitchState(Jason::Crawl_Idle_Right);
        }
            break;
        case Command::KeyUp:
            break;
        default:
            break;
        }

        break;
    }
    case PlayerType::SOPHIA:
        EntityID->sophia->Test();
        break;
    }
}