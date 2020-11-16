#include "Map_1_Actors.h"
#include "../ECS_Entity_Ex/Sophia.h"
#include "../ECS_Entity_Ex/Jason.h"
#include "../System/AnimationSystem.h"
#include "../System/SpriteSystem.h"
#include "../Core/Coordinator.h"
#include "../InputHandling/Core/InputContext.h"

Map_1_Actors::Map_1_Actors(short id) {
    this->id = id;
    coordinator = std::make_shared<Coordinator>();
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    animationSystem->coordinator = coordinator;
    std::shared_ptr<SpriteSystem> spriteSystem = coordinator->GetSystem<SpriteSystem>(SystemType::Sprite);
    spriteSystem->coordinator = coordinator;


    sophia = new Sophia(coordinator.get());
    jason = new Jason(coordinator.get());
}

void Map_1_Actors::Update(DWORD dt) {
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    animationSystem->Update();
}

void Map_1_Actors::Render() {
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    std::shared_ptr<SpriteSystem> spriteSystem = coordinator->GetSystem<SpriteSystem>(SystemType::Sprite);
    animationSystem->AnimationRender();
    spriteSystem->SpriteRender();
}