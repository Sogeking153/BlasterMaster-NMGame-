#include "Jason.h"
#include "../Core/Coordinator.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Component/TransformationComponent.h"
#include "../Component/DirectionComponent.h"
#include "../UtilHeader.h"
#include "../System/AnimationSystem.h"
#include "../System/SpriteSystem.h"
#include "../System/MovementSystem.h"
#include "../Debug.h"


Jason::Jason(std::shared_ptr<Coordinator> coordinator) {
    this->coordinator = coordinator;

    entityID = coordinator->CreateEntity();
 
    Position pos;
    pos.x = 100;
    pos.y = 64;

    coordinator->AddComponent<Position>(entityID, pos, ComponentType::Position);

    State jasonState;

    Animation jason_Ani_Idle;
    jason_Ani_Idle.textureID = JASON_IDLE_LEFT;
    jason_Ani_Idle.delayValue = 100;
    jason_Ani_Idle.isFinished = false;

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
    currentState = Jason::Idle_Left;

    Direction dir;
    coordinator->AddComponent<Direction>(entityID, dir, ComponentType::Direction);

    Velocity velocity;
    velocity.vx = 0;
    velocity.vy = 0;

    coordinator->AddComponent<Velocity>(entityID, velocity, ComponentType::Speed);

    coordinator->GetSystem<MovementSystem>(SystemType::Movement)->AddEntity(entityID);
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
    if (aniID == (int)currentState) return; //Avoid animation override when jason's animation in the middle of render and 

    Animation & animationNeedToSwap = coordinator->GetComponent<Animation>(entityID, ComponentType::Animation);
    switch (aniID)
    {
    case (int)Jason::Idle_Left: {
        Animation jason_Ani_Idle_Left;
        jason_Ani_Idle_Left.textureID = JASON_IDLE_LEFT;
        jason_Ani_Idle_Left.delayValue = 100;
        jason_Ani_Idle_Left.isFinished = false;

        State jasonState;
        jasonState.endFrame = 0;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Idle_Left.stateDictionary.emplace(JASON_IDLE_LEFT, jasonState);

        jason_Ani_Idle_Left.currentState = JASON_IDLE_LEFT;
        jason_Ani_Idle_Left.currentFrame = 0;
        jason_Ani_Idle_Left.defaultState = JASON_IDLE_LEFT;

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */

        //Swap Animation
        animationNeedToSwap = jason_Ani_Idle_Left;
        currentState = Jason::Idle_Left;

        //For testing only
        DebugOut(L"[INFO] Swap to IDLE_LEFT success\n");
        break;
    }
    case (int)Jason::Idle_Right: {
        Animation jason_Ani_Idle_Right;
        jason_Ani_Idle_Right.textureID = JASON_IDLE_RIGHT;
        jason_Ani_Idle_Right.delayValue = 100;
        jason_Ani_Idle_Right.isFinished = false;

        State jasonState;
        jasonState.endFrame = 1;
        jasonState.startFrame = 1;
        jasonState.isLoopable = true;
        jason_Ani_Idle_Right.stateDictionary.emplace(JASON_IDLE_RIGHT, jasonState);

        jason_Ani_Idle_Right.currentState = JASON_IDLE_RIGHT;
        jason_Ani_Idle_Right.currentFrame = 1;
        jason_Ani_Idle_Right.defaultState = JASON_IDLE_RIGHT;

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */

       //Swap Animation
        animationNeedToSwap = jason_Ani_Idle_Right;
        currentState = Jason::Idle_Right;

        //For testing only
        DebugOut(L"[INFO] Swap to IDLE_RIGHT success\n");
        break;
    }
    case (int)Jason::Walk_Left: {
        Animation jason_Ani_Walk_Left;
        jason_Ani_Walk_Left.textureID = JASON_GO_LEFT;
        jason_Ani_Walk_Left.delayValue = 100;
        jason_Ani_Walk_Left.isFinished = false;

        State jasonState;
        jasonState.endFrame = 3;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Walk_Left.stateDictionary.emplace(JASON_GO_LEFT, jasonState);
        
        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Walk_Left.currentState = JASON_GO_LEFT;
        jason_Ani_Walk_Left.currentFrame = 0;
        jason_Ani_Walk_Left.defaultState = JASON_GO_LEFT;

       //Swap Animation
        animationNeedToSwap = jason_Ani_Walk_Left;
        currentState = Jason::Walk_Left;

        //For testing only
        DebugOut(L"[INFO] Swap to WALK_LEFT success\n");
        break;
    }
    case (int)Jason::Walk_Right: {
        Animation jason_Ani_Walk_Right;
        jason_Ani_Walk_Right.textureID = JASON_GO_RIGHT;
        jason_Ani_Walk_Right.delayValue = 100;
        jason_Ani_Walk_Right.isFinished = false;

        State jasonState;
        jasonState.endFrame = 7;
        jasonState.startFrame = 4;
        jasonState.isLoopable = true;
        jason_Ani_Walk_Right.stateDictionary.emplace(JASON_GO_RIGHT, jasonState);


        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Walk_Right.currentState = JASON_GO_RIGHT;
        jason_Ani_Walk_Right.currentFrame = 4;
        jason_Ani_Walk_Right.defaultState = JASON_GO_RIGHT;

        //Swap Animation
        animationNeedToSwap = jason_Ani_Walk_Right;
        currentState = Jason::Walk_Right;

        //For testing only
        DebugOut(L"[INFO] Swap to WALK_RIGHT success\n");
        break;
    }
    case (int)Jason::Crawl_Idle_Left: {
        Animation jason_Ani_Crawl_Idle_Left;

        State jasonState;

        jason_Ani_Crawl_Idle_Left.textureID = JASON_CRAWL_LEFT;
        jason_Ani_Crawl_Idle_Left.delayValue = 100;
        jason_Ani_Crawl_Idle_Left.isFinished = false;

        jasonState.endFrame = 0;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Crawl_Idle_Left.stateDictionary.emplace(JASON_CRAWL_IDLE_LEFT, jasonState);

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Crawl_Idle_Left.currentState = JASON_CRAWL_IDLE_LEFT;
        jason_Ani_Crawl_Idle_Left.currentFrame = 0;
        jason_Ani_Crawl_Idle_Left.defaultState = JASON_CRAWL_IDLE_LEFT;

       //Swap Animation
        animationNeedToSwap = jason_Ani_Crawl_Idle_Left;
        currentState = Jason::Crawl_Idle_Left;

        //For testing only
        DebugOut(L"[INFO] Swap to CRAWL_IDLE_LEFT success\n");
        break;
    }
    case (int)Jason::Crawl_Idle_Right: {
        Animation jason_Ani_Crawl_Idle_Right;

        State jasonState;

        jason_Ani_Crawl_Idle_Right.textureID = JASON_CRAWL_RIGHT;
        jason_Ani_Crawl_Idle_Right.delayValue = 100;
        jason_Ani_Crawl_Idle_Right.isFinished = false;

        jasonState.endFrame = 3;
        jasonState.startFrame = 3;
        jasonState.isLoopable = true;
        jason_Ani_Crawl_Idle_Right.stateDictionary.emplace(JASON_CRAWL_IDLE_RIGHT, jasonState);

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Crawl_Idle_Right.currentState = JASON_CRAWL_IDLE_RIGHT;
        jason_Ani_Crawl_Idle_Right.currentFrame = 3;
        jason_Ani_Crawl_Idle_Right.defaultState = JASON_CRAWL_IDLE_RIGHT;

       //Swap Animation
        animationNeedToSwap = jason_Ani_Crawl_Idle_Right;
        currentState = Jason::Crawl_Idle_Right;

        //For testing only
        DebugOut(L"[INFO] Swap to CRAWL_IDLE_RIGHT success\n");
        break;
    }
    case (int)Jason::Crawl_Left: {
        Animation jason_Ani_Crawl_Left;

        State jasonState;

        jason_Ani_Crawl_Left.textureID = JASON_CRAWL_LEFT;
        jason_Ani_Crawl_Left.delayValue = 100;
        jason_Ani_Crawl_Left.isFinished = false;

        jasonState.endFrame = 1;
        jasonState.startFrame = 0;
        jasonState.isLoopable = true;
        jason_Ani_Crawl_Left.stateDictionary.emplace(JASON_CRAWL_LEFT, jasonState);

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Crawl_Left.currentState = JASON_CRAWL_LEFT;
        jason_Ani_Crawl_Left.currentFrame = 0;
        jason_Ani_Crawl_Left.defaultState = JASON_CRAWL_LEFT;

       //Swap Animation
        animationNeedToSwap = jason_Ani_Crawl_Left;
        currentState = Jason::Crawl_Left;

        //For testing only
        DebugOut(L"[INFO] Swap to CRAWL_LEFT success\n");
        break;
    }
    case (int)Jason::Crawl_Right: {
        Animation jason_Ani_Crawl_Right;

        State jasonState;

        jason_Ani_Crawl_Right.textureID = JASON_CRAWL_RIGHT;
        jason_Ani_Crawl_Right.delayValue = 100;
        jason_Ani_Crawl_Right.isFinished = false;

        jasonState.endFrame = 3;
        jasonState.startFrame = 2;
        jasonState.isLoopable = true;
        jason_Ani_Crawl_Right.stateDictionary.emplace(JASON_CRAWL_RIGHT, jasonState);

        /*
           TODO: Thuan should check whether jason is facing left or right to adjust current state and default state appropriately
       */
        jason_Ani_Crawl_Right.currentState = JASON_CRAWL_RIGHT;
        jason_Ani_Crawl_Right.currentFrame = 2;
        jason_Ani_Crawl_Right.defaultState = JASON_CRAWL_RIGHT;

       //Swap Animation
        animationNeedToSwap = jason_Ani_Crawl_Right;
        currentState = Jason::Crawl_Right;

        //For testing only
        DebugOut(L"[INFO] Swap to CRAWL_RIGHT success\n");
        break;
    }
    case (int)Jason::Climb: {
        Animation jason_Ani_Climb;
        State jasonState;

        jason_Ani_Climb.textureID = JASON_CLIMB_UP;
        jason_Ani_Climb.delayValue = 100;
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
        currentState = Jason::Climb;

        //For testing only
        DebugOut(L"[INFO] Swap to CLIMB success\n");
        break;
    }
    default:
        DebugOut(L"[ERROR] %d is incompatible with Jason animation's type\n");
        break;
    }
}
