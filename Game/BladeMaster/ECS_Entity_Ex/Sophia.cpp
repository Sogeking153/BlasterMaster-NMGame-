#include "Sophia.h"
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

Sophia::Sophia(Coordinator * coordinator) {
    entityID = coordinator->CreateEntity();
    Position Pos,temp;
    Pos.x = 64;  
    Pos.y = 64;

    coordinator->AddComponent<Position>(entityID, Pos, ComponentType::Position);

    bodyID = coordinator->CreateEntity();
    coordinator->AddComponent<Position>(bodyID, Pos, ComponentType::Position);
    Animation bodyAni;
    bodyAni.textureID = BODY_SOPHIA;
    bodyAni.delayValue = 1000;
	bodyAni.isFinished = false;
    State state;
    state.endFrame= 0;
    state.startFrame = 0;
    state.isLoopable = true;
    bodyAni.stateDictionary.emplace(BODY_CAR_IDLE_LEFT, state);

    state.endFrame = 2;
    state.startFrame = 2;
    state.isLoopable = true;
    bodyAni.stateDictionary.emplace(BODY_CAR_IDLE_RIGHT, state);

    state.startFrame = 0;
    state.endFrame = 2;
    state.isLoopable = false;
    bodyAni.stateDictionary.emplace(CAR_CHANGE_DIRECTION, state);
    bodyAni.currentState = BODY_CAR_IDLE_LEFT;
	bodyAni.currentFrame = 0;
    bodyAni.defaultState = BODY_CAR_IDLE_LEFT;
    coordinator->AddComponent<Animation>(bodyID, bodyAni, ComponentType::Animation);
 
    Transformation transform;
    D3DXMatrixTransformation2D(
        &transform.transformMatrix,
        NULL,
        NULL,
        NULL,
        NULL,
        0,
        &D3DXVECTOR2(5, 0)
    );
    coordinator->AddComponent<Transformation>(bodyID, transform, ComponentType::Transformation);
    coordinator->GetSystem<AnimationSystem>(SystemType::Animation)->AddEntity(bodyID);

    axelID = coordinator->CreateEntity();
    temp.x = Pos.x + 4; //Entity Pos.x + 4
    temp.y = Pos.y + 8; //Entity Pos.y + 8
    Sprite sprite;
    sprite.spriteID = 0;
    sprite.textureID = AXEL_SOPHIA;
    coordinator->AddComponent<Position>(axelID, temp, ComponentType::Position);
    coordinator->AddComponent<Sprite>(axelID, sprite, ComponentType::Sprite);

    coordinator->GetSystem<SpriteSystem>(SystemType::Sprite)->AddEntity(axelID);

    wheel1ID = coordinator->CreateEntity();
    Sprite wheelSprite;
    wheelSprite.textureID = WHEEL_SOPHIA;
    wheelSprite.spriteID = 0;
    coordinator->AddComponent<Position>(wheel1ID, Pos, ComponentType::Position);
    coordinator->AddComponent<Sprite>(wheel1ID, wheelSprite, ComponentType::Sprite);

    Transformation wheel1Transform;
    D3DXMatrixTransformation2D(
        &wheel1Transform.transformMatrix,
        NULL,
        NULL,
        NULL,
        NULL,
        0,
        &D3DXVECTOR2(-3, 9)
    );
    coordinator->AddComponent<Transformation>(wheel1ID, wheel1Transform, ComponentType::Transformation);

    coordinator->GetSystem<SpriteSystem>(SystemType::Sprite)->AddEntity(wheel1ID);

    wheel2ID = coordinator->CreateEntity();
    coordinator->AddComponent<Position>(wheel2ID, Pos, ComponentType::Position);
    coordinator->AddComponent<Sprite>(wheel2ID, wheelSprite, ComponentType::Sprite);

    Transformation wheel2Transform;
    D3DXMatrixTransformation2D(
        &wheel2Transform.transformMatrix,
        NULL,
        NULL,
        NULL,
        NULL,
        0,
        &D3DXVECTOR2(12, 9)
    );
    coordinator->AddComponent<Transformation>(wheel2ID, wheel2Transform, ComponentType::Transformation);

    coordinator->GetSystem<SpriteSystem>(SystemType::Sprite)->AddEntity(wheel2ID);

    barrelID = coordinator->CreateEntity();
    temp.x = Pos.x - 3; //Entity Pos.x - 3
    temp.y = Pos.y; //Entity Pos.y
    coordinator->AddComponent<Position>(barrelID, temp, ComponentType::Position);
    Animation barrelAni;
    barrelAni.textureID = BARREL_SOPHIA;
    bodyAni.delayValue = 1000;
    bodyAni.isFinished = false;
    State barrelState;
    barrelState.endFrame = 0;
    barrelState.startFrame = 0;
    barrelState.isLoopable = true;
    barrelAni.stateDictionary.emplace(BARREL_IDLE_RIGHT, barrelState);

    barrelState.endFrame = 3;
    barrelState.startFrame = 3;
    barrelState.isLoopable = true;
    barrelAni.stateDictionary.emplace(BARREL_IDLE_LEFT, barrelState);

    barrelState.endFrame = 2;
    barrelState.startFrame = 2;
    barrelState.isLoopable = true;
    barrelAni.stateDictionary.emplace(BARREL_IDLE_TOP, barrelState);

    barrelState.endFrame = 2;
    barrelState.startFrame = 0;
    barrelState.isLoopable = false;
    barrelAni.stateDictionary.emplace(BARREL_LOOK_UP_RIGHT, barrelState);

    barrelState.endFrame = 5;
    barrelState.startFrame = 3;
    barrelState.isLoopable = false;
    barrelAni.stateDictionary.emplace(BARREL_LOOK_UP_LEFT, barrelState);
    barrelAni.currentState = BARREL_IDLE_LEFT;
    barrelAni.currentFrame = 3;
    barrelAni.defaultState = BARREL_IDLE_LEFT;
    coordinator->AddComponent<Animation>(barrelID, barrelAni, ComponentType::Animation);
    coordinator->GetSystem<AnimationSystem>(SystemType::Animation)->AddEntity(barrelID);
}

int Sophia::GetID() {
    return entityID;
}

void Sophia::Test()
{
    DebugOut(L"This is Sophia\n");
}
