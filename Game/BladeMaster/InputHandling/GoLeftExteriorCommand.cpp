#include "GoLeftExteriorCommand.h"
#include "../HelperHeader/PlayerType.h"
//For testing purpose
#include "../Debug.h"
#include "Core/InputContext.h"
#include "../Core/Coordinator.h"
#include"../Component/SpeedComponent.h"
#include "../Component/PositionComponent.h"
#include "../Component/AnimationComponent.h"
#include "../System/AnimationSystem.h"

void GoLeftExteriorCommand::execute(int EntityID) 
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


void GoLeftExteriorCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Go Left Exterior Command\n");
    
    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
        EntityID->jason->Test();
        break;
    case PlayerType::SOPHIA:
        EntityID->sophia->Test();
        break;
    }

}