#include "JumpCommand.h"
//For testing purpose

#include "../Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../System/AnimationSystem.h"
#include "../UtilHeader.h"
#include "../HelperHeader/PlayerType.h"
#include "../HelperHeader/Debug.h"

void JumpCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Jump Command\n");
    InputContext* context = InputContext::GetInstance();

    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
    {
        switch (currentKeyEventType)
        {
        case Command::Hold:
        {

            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
            velocity.vy = JASON_JUMPING_SPEED;
            Direction& dir = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
            dir.nx = -1;
            
            switch (EntityID->jason->currentState)
            {
            case Jason::Walk_Left:
            case Jason::Idle_Left:
            case Jason::Walk_Right:
            case Jason::Idle_Right:
                EntityID->jason->SwitchState(Jason::Walk_Left);
                break;
            case Jason::Crawl_Left:
            case Jason::Crawl_Idle_Left:
            case Jason::Crawl_Idle_Right:
            case Jason::Crawl_Right:
                EntityID->jason->SwitchState(Jason::Crawl_Left);
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
            case Jason::Walk_Left:
            case Jason::Idle_Left:
                EntityID->jason->SwitchState(Jason::Idle_Left);
                break;
            case Jason::Crawl_Left:
            case Jason::Crawl_Idle_Left:
                EntityID->jason->SwitchState(Jason::Crawl_Idle_Left);
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