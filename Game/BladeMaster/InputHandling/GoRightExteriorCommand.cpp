#include "GoRightExteriorCommand.h"
#include "../HelperHeader/Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../System/AnimationSystem.h"
#include "../HelperHeader/UtilHeader.h"
#include "../HelperHeader/PlayerType.h"

void GoRightExteriorCommand::execute(PlayerType * EntityID) {
    //DebugOut(L"Go Right Exterior Command\n");
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
        switch (currentKeyEventType)
        {
        case Command::Hold:
        {
            if (EntityID->jason->currentState == Sophia::Go_Left || EntityID->jason->currentState == Sophia::Idle_Left)
            {
                EntityID->sophia->SwitchState(Sophia::Body_Shift_Left);

            }

            if (EntityID->jason->currentState == Sophia::Body_Shift_Left)
            {
                EntityID->sophia->SwitchState(Sophia::Idle_Right);
            }
           

            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->sophia->GetID(), ComponentType::Speed);
            velocity.vx = 0.05;
            Direction& dir = context->coordinator->GetComponent<Direction>(EntityID->sophia->GetID(), ComponentType::Direction);
            dir.nx = 1;
            switch (EntityID->jason->currentState)
            {
            case Sophia::Go_Right:
            case Sophia::Idle_Right:
                EntityID->sophia->SwitchState(Sophia::Go_Right);
            case Sophia::Go_Left:
            case Sophia::Idle_Left:
                EntityID->sophia->SwitchState(Sophia::Left_To_Right);
            default:
                break;
            }
            EntityID->sophia->SwitchState(Sophia::Go_Right);

            EntityID->sophia->PartPosUpdateRight();

        }
        break;
        case Command::KeyDown:
        {

        }
            break;
        case Command::KeyUp:
        {
            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->sophia->GetID(), ComponentType::Speed);
            velocity.vx = 0;
            EntityID->sophia->SwitchState(Sophia::Idle_Right);
            EntityID->sophia->PartPosUpdateRight();
        }
        break;
        default:
            break;
        }
        break;
    }
}