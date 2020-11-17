#include "GoRightExteriorCommand.h"
#include "../Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../System/AnimationSystem.h"
#include "../UtilHeader.h"
#include "../HelperHeader/PlayerType.h"

void GoRightExteriorCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Go Right Exterior Command\n");
    InputContext* context = InputContext::GetInstance();

    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
    {
        switch (currentKeyEventType)
        {
        case Command::Hold:
        {
            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
            velocity.vx = JASON_WALKING_SPEED;
            Direction& dir = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
            dir.nx = 1;

            switch (EntityID->jason->currentState)
            {
            case Jason::Walk_Left:
            case Jason::Idle_Left:
            case Jason::Walk_Right:
            case Jason::Idle_Right:
                EntityID->jason->SwitchState(Jason::Walk_Right);
                break;
            case Jason::Crawl_Left:
            case Jason::Crawl_Idle_Left:
            case Jason::Crawl_Idle_Right:
            case Jason::Crawl_Right:
                EntityID->jason->SwitchState(Jason::Crawl_Right);
                break;
            default:
                break;
            }
        }
        break;
        case Command::KeyDown:
            break;
        case Command::KeyUp:
        {
            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
            velocity.vx = 0;
            
            switch (EntityID->jason->currentState)
            {
            case Jason::Walk_Right:
            case Jason::Idle_Right:
                EntityID->jason->SwitchState(Jason::Idle_Right);
                break;
            case Jason::Crawl_Right:
            case Jason::Crawl_Idle_Right:
                EntityID->jason->SwitchState(Jason::Crawl_Idle_Right);
                break;
            default:
                break;
            }
        }
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