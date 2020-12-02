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
        //time Last_shot = 0 //Variable storing time the latest shot is fired, this variable value must not be lost during game run
        //time Rate_of_fire = 500 //Variable for rate-of-fire
    case PlayerType::JASON: {
        //int Bullet_type = 1 //initiating bullet type variable
        switch (currentKeyEventType)
        {
        case Command::KeyDown: {
            //time Get_current_time //Variable storing time of the current keypress, may need an universal game time variable
            /*if (Get_current_time - Last_shot < Rate_of_fire) //Check if the button is pressed before the cooldown needed for another shot 
            {
                break; //If gun is still in cooldown then bypass bullet creation
            }
            else 
            {
                Last_shot = Get_current_time; //If gun has completed cooldown then create bullet, then update last shot time
            }*/
            Position position;
            position = context->coordinator->GetComponent<Position>(EntityID->jason->GetID(), ComponentType::Position);
            Direction direction;
            direction = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
            Bullet1 bullet(context->coordinator, position, direction); //can add int bullet type to determine which bullet is it
        }
        break;
        case Command::Hold:
        {
            while (true) {
                Position position;
                position = context->coordinator->GetComponent<Position>(EntityID->jason->GetID(), ComponentType::Position);
                Direction direction;
                direction = context->coordinator->GetComponent<Direction>(EntityID->jason->GetID(), ComponentType::Direction);
                Bullet1 bullet(context->coordinator, position, direction);
                }
            }
        break;
        case Command::KeyUp:
        break;
        default:
            break;
        }
    }
    case PlayerType::SOPHIA:
    {
        //int Bullet_type = 2;
        switch (currentKeyEventType)
        {
        case Command::KeyDown: {
            Position position;
            position = context->coordinator->GetComponent<Position>(EntityID->sophia->GetID(), ComponentType::Position);
            Direction direction;
            direction = context->coordinator->GetComponent<Direction>(EntityID->sophia->GetID(), ComponentType::Direction);
            Bullet1 bullet(context->coordinator, position, direction); //can add int bullet type to determine which bullet is it
        }
        break;
        case Command::Hold:
        {
            while (true) {
                Position position;
                position = context->coordinator->GetComponent<Position>(EntityID->sophia->GetID(), ComponentType::Position);
                Direction direction;
                direction = context->coordinator->GetComponent<Direction>(EntityID->sophia->GetID(), ComponentType::Direction);
                Bullet1 bullet(context->coordinator, position, direction);
            }
        }
        break;
        case Command::KeyUp:
            break;
        default:
            break;
        }
    }
}