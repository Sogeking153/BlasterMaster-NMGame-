#pragma once
#include "JasonOW.h"
#include "../Core/Coordinator.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Component/TransformationComponent.h"
#include "../HelperHeader/UtilHeader.h"
#include "../System/AnimationSystem.h"
#include "../System/SpriteSystem.h"
#include "../HelperHeader/Debug.h"



JasonOW::JasonOW(Coordinator* coordinator) {
    entityID = coordinator->CreateEntity();

    Position pos;
    pos.x = 256;
    pos.y = 256;

    coordinator->AddComponent<Position>(entityID, pos, ComponentType::Position);

    State jasonState;

    Animation jason_OW_UP;
    jason_OW_UP.textureID = JASON_O_UP;
    jason_OW_UP.delayValue = 100;
    jason_OW_UP.isFinished = false;

    jasonState.endFrame = 17;
    jasonState.startFrame = 0;
    jasonState.isLoopable = true;
    jason_OW_UP.stateDictionary.emplace(JASON_O_UP, jasonState);

    jason_OW_UP.currentState = JASON_O_UP;
    jason_OW_UP.currentFrame = 0;
    jason_OW_UP.defaultState = JASON_O_UP;


    Animation jason_OW_DOWN;
    jason_OW_DOWN.textureID = JASON_O_DOWN;
    jason_OW_DOWN.delayValue = 100;
    jason_OW_DOWN.isFinished = false;

    jasonState.endFrame = 3;
    jasonState.startFrame = 0;
    jasonState.isLoopable = false;
    jason_OW_DOWN.stateDictionary.emplace(JASON_O_DOWN, jasonState);

    jason_OW_DOWN.currentState = JASON_O_DOWN;
    jason_OW_DOWN.currentFrame = 0;
    jason_OW_DOWN.defaultState = JASON_O_DOWN;

    Animation jason_OW_LEFT;
    jason_OW_LEFT.textureID = JASON_O_LEFT;
    jason_OW_LEFT.delayValue = 100;
    jason_OW_LEFT.isFinished = false;

    jasonState.endFrame = 3;
    jasonState.startFrame = 0;
    jasonState.isLoopable = false;
    jason_OW_LEFT.stateDictionary.emplace(JASON_O_LEFT, jasonState);

    jason_OW_LEFT.currentState = JASON_O_LEFT;
    jason_OW_LEFT.currentFrame = 0;
    jason_OW_LEFT.defaultState = JASON_O_LEFT;

    Animation jason_OW_RIGHT;
    jason_OW_RIGHT.textureID = JASON_O_RIGHT;
    jason_OW_RIGHT.delayValue = 100;
    jason_OW_RIGHT.isFinished = false;

    jasonState.endFrame = 3;
    jasonState.startFrame = 0;
    jasonState.isLoopable = false;
    jason_OW_RIGHT.stateDictionary.emplace(JASON_O_RIGHT, jasonState);

    jason_OW_RIGHT.currentState = JASON_O_RIGHT;
    jason_OW_RIGHT.currentFrame = 0;
    jason_OW_RIGHT.defaultState = JASON_O_RIGHT;

    Animation jason_OW_DIE;
    jason_OW_DIE.textureID = JASON_O_DIE;
    jason_OW_DIE.delayValue = 100;
    jason_OW_DIE.isFinished = false;

    jasonState.endFrame = 15;
    jasonState.startFrame = 0;
    jasonState.isLoopable = false;
    jason_OW_DIE.stateDictionary.emplace(JASON_O_DIE, jasonState);

    jason_OW_DIE.currentState = JASON_O_DIE;
    jason_OW_DIE.currentFrame = 0;
    jason_OW_DIE.defaultState = JASON_O_DIE;


    coordinator->AddComponent<Animation>(entityID, jason_OW_UP, ComponentType::Animation);
    coordinator->GetSystem<AnimationSystem>(SystemType::Animation)->AddEntity(entityID);

}



int JasonOW::GetID() {
    return entityID;
}

void JasonOW::Test()
{
    DebugOut(L"This is Jason\n");
}
