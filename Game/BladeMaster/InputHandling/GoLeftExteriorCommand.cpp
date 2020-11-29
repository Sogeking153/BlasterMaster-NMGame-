#include "GoLeftExteriorCommand.h"
#include "../HelperHeader/Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../System/AnimationSystem.h"
#include "../HelperHeader/UtilHeader.h"
#include "../HelperHeader/PlayerType.h"

/*void GoLeftExteriorCommand::execute(PlayerType * EntityID)
{
    DebugOut(L"Go Left Exterior Command\n");
    InputContext* context = InputContext::GetInstance();
    DebugOut(L"%d\n", context->coordinator);
    //context->coordinator->GetComponent<Animation>(EntityID, ComponentType::Animation);

    Position pos = context->coordinator->GetComponent<Position>(EntityID, ComponentType::Position);;

    pos.x = pos.x + 10;
   // DebugOut(L"%d, %d\n", pos.x, &pos.y);
   /* Velocity vel;
    vel.vx = 10;

    pos.x = pos.x + vel.vx;
    context->coordinator->AddComponent<Position>(EntityID, pos, ComponentType::Position);
    context->coordinator->GetSystem<AnimationSystem>(SystemType::Animation)->AddEntity(EntityID);*/


void GoLeftExteriorCommand::execute(PlayerType* EntityID) {
    DebugOut(L"Go Left Exterior Command\n\n");
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
        {
            switch (EntityID->jason->currentState)
            {
            case Jason::Jump_Right:
                EntityID->jason->SwitchState(Jason::Jump_Left);
                break;
            default:
                break;
            }
        }
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
        switch (currentKeyEventType)
        {
        case Command::Hold:
        {
            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->sophia->GetID(), ComponentType::Speed);
            velocity.vx = 0.005;
            Direction& dir = context->coordinator->GetComponent<Direction>(EntityID->sophia->GetID(), ComponentType::Direction);
            dir.nx = -1;  
            switch (EntityID->jason->currentState)
            {
            case Sophia::Go_Left:
            case Sophia::Idle_Left:
                EntityID->sophia->SwitchState(Sophia::Go_Left);
            case Sophia::Go_Right:
            case Sophia::Idle_Right:
                EntityID->sophia->SwitchState(Sophia::Right_To_Left);
            default:
                break;
            }
            EntityID->sophia->SwitchState(Sophia::Go_Left);
            EntityID->sophia->PartPosUpdate();
            
        }
            break;
        case Command::KeyDown:

            break;
        case Command::KeyUp:
        {
            Velocity& velocity = context->coordinator->GetComponent<Velocity>(EntityID->sophia->GetID(), ComponentType::Speed);
            velocity.vx = 0;
            EntityID->sophia->SwitchState(Sophia::Idle_Left);
            EntityID->sophia->PartPosUpdate();
        }
            break;
        default:
            break;
        }
        break;
    }

}