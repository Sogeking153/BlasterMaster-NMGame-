#include "ShootExteriorCommand.h"
#include "../HelperHeader/Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../System/AnimationSystem.h"
#include "../HelperHeader/UtilHeader.h"
#include "../HelperHeader/PlayerType.h"
#include "../ECS_Entity_Ex/Bullet1.h"
//For testing purpose
#include "../HelperHeader/Debug.h"

void ShootExteriorCommand::execute(PlayerType* EntityID) {
    DebugOut(L"Shoot Exterior Command\n");

    InputContext* context = InputContext::GetInstance();
    switch (EntityID->currentPlayerType) 
    {
    case PlayerType::JASON:
    {
        switch (currentKeyEventType)
        {
        case Command::Hold:
        case Command::KeyDown: {
            Position position;
            position = context->coordinator->GetComponent<Position>(EntityID->jason->GetID(), ComponentType::Position);
            Direction direction;
            direction = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
            Bullet1 bullet(context->coordinator, position, direction);
            break;
        }
        case Command::KeyUp:
            break;
        default:
            break;
        }

        break;
    }
    case PlayerType::SOPHIA:
    {
        switch (currentKeyEventType)
        {
        case Command::Hold:
        case Command::KeyDown: {
            Position position;
            position = context->coordinator->GetComponent<Position>(EntityID->sophia->GetID(), ComponentType::Position);
            Direction direction;
            direction = context->coordinator->GetComponent<Direction>(EntityID->sophia->GetID(), ComponentType::Direction);
            Bullet1 bullet(context->coordinator, position, direction);
            break;
        }
        case Command::KeyUp:
            break;
        default:
            break;
        }
    }
    }
}