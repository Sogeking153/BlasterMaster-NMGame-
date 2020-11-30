#include "AimUpcommand.h"
//For testing purpose
#include "../HelperHeader/Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../Component/AnimationComponent.h"
#include "../System/AnimationSystem.h"
#include "../HelperHeader/UtilHeader.h"
#include "../HelperHeader/PlayerType.h"

void AimUpCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Aim Up Command\n");

    InputContext* context = InputContext::GetInstance();

    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
    {
        switch (currentKeyEventType)
        {
        case Command::Hold:
        {

           /* Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
            velocity.vx = JASON_WALKING_SPEED;*/
           /* Direction& dir = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
            dir.nx = -1;*/

            DebugOut(L"No help");

        }
        break;
        case Command::KeyDown:
        {
            switch (EntityID->jason->currentState)
            {
            case Jason::Crawl_Left:
            case Jason::Crawl_Idle_Left:
                EntityID->jason->SwitchState(Jason::Idle_Left);
                break;
            case Jason::Crawl_Idle_Right:
            case Jason::Crawl_Right:
                EntityID->jason->SwitchState(Jason::Idle_Right);
                break;
            default:
                DebugOut(L"NO");
                break;
            }
        }
            break;
        case Command::KeyUp:
        {
           /* Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->jason->GetID(), ComponentType::Speed);
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
            }*/
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