#include "Bullet1.h"
#include "../Core/Coordinator.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Component/TransformationComponent.h"
#include "../Component/DirectionComponent.h"
#include "../HelperHeader/UtilHeader.h"
#include "../System/AnimationSystem.h"
#include "../System/SpriteSystem.h"
#include "../System/MovementSystem.h"
#include "../HelperHeader/Debug.h"

Bullet1::Bullet1(Coordinator* coordinator, Position position, Direction direction) {
    entityID = coordinator->CreateEntity();

    Position pos;
    pos.x = position.x;
    pos.y = position.y;

    coordinator->AddComponent<Position>(entityID, pos, ComponentType::Position);

    Sprite bullet;
    bullet.textureID = JASON_GO_RIGHT;
    bullet.spriteID = 0;

    coordinator->AddComponent<Sprite>(entityID, bullet, ComponentType::Sprite);
    coordinator->GetSystem<SpriteSystem>(SystemType::Sprite)->AddEntity(entityID);

    
    Direction dir;
    dir = direction;
    coordinator->AddComponent<Direction>(entityID, dir, ComponentType::Direction);

    Velocity velocity;
    velocity.vx = 0.05;
    velocity.vy = 0;

    coordinator->AddComponent<Velocity>(entityID, velocity, ComponentType::Speed);

    coordinator->GetSystem<MovementSystem>(SystemType::Movement)->AddEntity(entityID);
}

int Bullet1::GetID() {
    return entityID;
}

//This for testing only
//Don't do anything about it
void Bullet1::Test()
{
    DebugOut(L"Bullet created\n");
}