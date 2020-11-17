#include "Jason.h"
#include "../Core/Coordinator.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Component/TransformationComponent.h"
#include "../UtilHeader.h"
#include "../System/AnimationSystem.h"
#include "../System/SpriteSystem.h"
#include "../Debug.h"


Jason::Jason(std::shared_ptr<Coordinator> coordinator) {
    this->coordinator = coordinator;

    entityID = coordinator->CreateEntity();
 
    Position pos;
    pos.x = 100;
    pos.y = 64;

    coordinator->AddComponent<Position>(entityID, pos, ComponentType::Position);

    Animation jason_Ani_Idle;
    jason_Ani_Idle.textureID = JASON_IDLE;
    jason_Ani_Idle.delayValue = 100;
    jason_Ani_Idle.isFinished = false;

    State jasonState;
    jasonState.endFrame = 0;
    jasonState.startFrame = 0;
    jasonState.isLoopable = true;
    jason_Ani_Idle.stateDictionary.emplace(JASON_IDLE_LEFT, jasonState);

    jasonState.endFrame = 1;
    jasonState.startFrame = 1;
    jasonState.isLoopable = true;
    jason_Ani_Idle.stateDictionary.emplace(JASON_IDLE_RIGHT, jasonState);
    
    jason_Ani_Idle.currentState = JASON_IDLE_LEFT;
    jason_Ani_Idle.currentFrame = 0;
    jason_Ani_Idle.defaultState = JASON_IDLE_LEFT;


    coordinator->AddComponent<Animation>(entityID, jason_Ani_Idle, ComponentType::Animation);
    coordinator->GetSystem<AnimationSystem>(SystemType::Animation)->AddEntity(entityID);

    //Default Animation
    currentAnimation = Jason::Idle;
}

int Jason::GetID() {
    return entityID;
}

//This for testing only
//Don't do anything about it
void Jason::Test()
{
    DebugOut(L"This is Jason\n");
}

/*
    I don't want to change jason's animation anywhere beside this
*/
void Jason::SwitchState(int aniID)
{
    if (aniID == (int)currentAnimation) return; //Avoid animation override when jason's animation in the middle of render and 

    Animation & animationNeedToSwap = coordinator->GetComponent<Animation>(entityID, ComponentType::Animation);
    switch (aniID)
    {
    case (int)Jason::Idle: {
        Animation jason_Ani_Idle;
        jason_Ani_Idle.textureID = JASON_IDLE;
        jason_Ani_Idle.delayValue = 100;
        jason_Ani_Idle.isFinished = false;

        State jasonState;
        jasonState.endFrame = 0;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Idle.stateDictionary.emplace(JASON_IDLE_LEFT, jasonState);

        jasonState.endFrame = 1;
        jasonState.startFrame = 1;
        jasonState.isLoopable = true;
        jason_Ani_Idle.stateDictionary.emplace(JASON_IDLE_RIGHT, jasonState);

        jason_Ani_Idle.currentState = JASON_IDLE_LEFT;
        jason_Ani_Idle.currentFrame = 0;
        jason_Ani_Idle.defaultState = JASON_IDLE_LEFT;

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */

        //Swap Animation
        animationNeedToSwap = jason_Ani_Idle;
        currentAnimation = Jason::Idle;

        //For testing only
        DebugOut(L"[INFO] Swap to IDLE success\n");
        break;
    }
    case (int)Jason::Walk: {
        Animation jason_Ani_Walk;
        jason_Ani_Walk.textureID = JASON_WALK;
        jason_Ani_Walk.delayValue = 1000;
        jason_Ani_Walk.isFinished = false;

        State jasonState;
        jasonState.endFrame = 3;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Walk.stateDictionary.emplace(JASON_GO_LEFT, jasonState);

        jasonState.endFrame = 7;
        jasonState.startFrame = 4;
        jasonState.isLoopable = true;
        jason_Ani_Walk.stateDictionary.emplace(JASON_GO_RIGHT, jasonState);
        
        
        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Walk.currentState = JASON_GO_LEFT;
        jason_Ani_Walk.currentFrame = 0;
        jason_Ani_Walk.defaultState = JASON_GO_LEFT;

       //Swap Animation
        animationNeedToSwap = jason_Ani_Walk;
        currentAnimation = Jason::Walk;

        //For testing only
        DebugOut(L"[INFO] Swap to WALK success\n");
        break;
    }
    case (int)Jason::Crawl: {
        Animation jason_Ani_Crawl;

        State jasonState;

        jason_Ani_Crawl.textureID = JASON_CRAWL;
        jason_Ani_Crawl.delayValue = 1000;
        jason_Ani_Crawl.isFinished = false;

        jasonState.endFrame = 1;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Crawl.stateDictionary.emplace(JASON_CRAWL_LEFT, jasonState);

        jasonState.endFrame = 3;
        jasonState.startFrame = 2;
        jasonState.isLoopable = true;
        jason_Ani_Crawl.stateDictionary.emplace(JASON_CRAWL_RIGHT, jasonState);

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Crawl.currentState = JASON_CRAWL_LEFT;
        jason_Ani_Crawl.currentFrame = 0;
        jason_Ani_Crawl.defaultState = JASON_CRAWL_LEFT;

       //Swap Animation
        animationNeedToSwap = jason_Ani_Crawl;
        currentAnimation = Jason::Crawl;

        //For testing only
        DebugOut(L"[INFO] Swap to CRAWL success\n");
        break;
    }
    case (int)Jason::Climb: {
        Animation jason_Ani_Climb;
        State jasonState;

        jason_Ani_Climb.textureID = JASON_CLIMB;
        jason_Ani_Climb.delayValue = 1000;
        jason_Ani_Climb.isFinished = false;

        jasonState.endFrame = 1;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Climb.stateDictionary.emplace(JASON_CLIMB_UP, jasonState);

        /*
              TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
         */
        jason_Ani_Climb.currentState = JASON_CLIMB_UP;
        jason_Ani_Climb.currentFrame = 0;
        jason_Ani_Climb.defaultState = JASON_CLIMB_UP;

        //Swap Animation
        animationNeedToSwap = jason_Ani_Climb;
        currentAnimation = Jason::Climb;

        //For testing only
        DebugOut(L"[INFO] Swap to CLIMB success\n");
        break;
    }
    default:
        DebugOut(L"[ERROR] %d is incompatible with Jason animation's type\n");
        break;
    }
}
