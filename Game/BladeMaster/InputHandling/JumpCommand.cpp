#include "JumpCommand.h"
//For testing purpose

#include "../HelperHeader/Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../System/AnimationSystem.h"
#include "../HelperHeader/UtilHeader.h"
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
            break;
        case Command::KeyDown:
        {

            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
            velocity.vy = -JASON_JUMPING_SPEED;
            Direction& dir = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
            Position& pos = context->coordinator->GetComponent<Position>(EntityID->jason->GetID(), ComponentType::Position);

            switch (EntityID->jason->currentState)
            {
            case Jason::Walk_Left:
            case Jason::Idle_Left:
            case Jason::Jump_Right:
            {
                if (dir.nx == -1 && pos.y==64)
                    EntityID->jason->SwitchState(Jason::Jump_Left);
                break;
            }
            case Jason::Walk_Right:
            case Jason::Idle_Right:
            case Jason::Jump_Left:
            {
                if (dir.nx == 1 && pos.y == 64)
                    EntityID->jason->SwitchState(Jason::Jump_Right);
                break;
            }

            default:
                break;
            }

        }
            break;
        case Command::KeyUp:
        {
            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
            velocity.vy = 0;


            switch (EntityID->jason->currentState)
            {
            case Jason::Jump_Left:
                EntityID->jason->SwitchState(Jason::Idle_Left);
                break;
            case Jason::Jump_Right:
                EntityID->jason->SwitchState(Jason::Idle_Right);
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
        
        break;
    }
}