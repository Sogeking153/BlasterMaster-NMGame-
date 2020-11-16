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

Jason::Jason(Coordinator* coordinator) {
    entityID = coordinator->CreateEntity();

    Position pos;
    pos.x = 100;
    pos.y = 64;

    coordinator->AddComponent<Position>(entityID, pos, ComponentType::Position);

    Animation jason_Ani_Idle;
    jason_Ani_Idle.textureID = JASON;
    jason_Ani_Idle.delayValue = 1000;
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
    
    Animation jason_Ani_Walk;
    jason_Ani_Walk.textureID = JASON_WALK;
    jason_Ani_Walk.delayValue = 1000;
    jason_Ani_Walk.isFinished = false;

    jasonState.endFrame = 3;
    jasonState.startFrame = 0;
    jasonState.isLoopable = true;
    jason_Ani_Walk.stateDictionary.emplace(JASON_GO_LEFT, jasonState);

    jasonState.endFrame = 7;
    jasonState.startFrame = 4;
    jasonState.isLoopable = true;
    jason_Ani_Walk.stateDictionary.emplace(JASON_GO_RIGHT, jasonState);

    Animation jason_Ani_Crawl;

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

    Animation jason_Ani_Climb;
    jason_Ani_Climb.textureID = JASON_CLIMB;
    jason_Ani_Climb.delayValue = 1000;
    jason_Ani_Climb.isFinished = false;

    jasonState.endFrame = 1;
    jasonState.startFrame = 0;
    jasonState.isLoopable = true;
    jason_Ani_Climb.stateDictionary.emplace(JASON_CLIMB_UP, jasonState);

    jason_Ani_Idle.currentState = JASON_IDLE_LEFT;
    jason_Ani_Idle.currentFrame = 0;
    jason_Ani_Idle.defaultState = JASON_IDLE_LEFT;

    jason_Ani_Walk.currentState = JASON_GO_LEFT;
    jason_Ani_Walk.currentFrame = 0;
    jason_Ani_Walk.defaultState = JASON_GO_LEFT;

    jason_Ani_Crawl.currentState = JASON_CRAWL_LEFT;
    jason_Ani_Crawl.currentFrame = 0;
    jason_Ani_Crawl.defaultState = JASON_CRAWL_LEFT;

    jason_Ani_Climb.currentState = JASON_CLIMB_UP;
    jason_Ani_Climb.currentFrame = 0;
    jason_Ani_Climb.defaultState = JASON_CLIMB_UP;


    coordinator->AddComponent<Animation>(entityID, jason_Ani_Idle, ComponentType::Animation);
    coordinator->GetSystem<AnimationSystem>(SystemType::Animation)->AddEntity(entityID);

}

int Jason::GetID() {
    return entityID;
}