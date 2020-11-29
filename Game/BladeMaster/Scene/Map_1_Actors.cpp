#include "Map_1_Actors.h"
#include "../ECS_Entity_Ex/Sophia.h"
#include "../ECS_Entity_Ex/Jason.h"
#include "../ECS_Entity_Ex/JasonOW.h"
#include "../System/AnimationSystem.h"
#include "../System/SpriteSystem.h"
#include "../Core/Coordinator.h"
#include "../InputHandling/Core/InputContext.h"
#include "../HelperHeader/PlayerType.h"
#include "../System/MovementSystem.h"
#include "../Camera.h"
Map_1_Actors::Map_1_Actors(short id) {
    this->id = id;
    //Setup System
    coordinator = std::make_shared<Coordinator>();
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    animationSystem->coordinator = coordinator;
    std::shared_ptr<SpriteSystem> spriteSystem = coordinator->GetSystem<SpriteSystem>(SystemType::Sprite);
    spriteSystem->coordinator = coordinator;
    std::shared_ptr<MovementSystem> movementSystem = coordinator->GetSystem<MovementSystem>(SystemType::Movement);
    movementSystem->coordinator = coordinator;

    //Setup player
    sophia = new Sophia(coordinator.get());
    jason = new Jason(coordinator);
    jasonow = new JasonOW(coordinator.get());

    //Setup Input
    InputContext* input = InputContext::GetInstance();
    input->coordinator = coordinator.get();
    input->player->currentPlayerType = PlayerType::JASONOW;
    input->player->jasonow = jasonow;

    //Setup Camera
    Camera* camera = Camera::GetInstance();
    camera->Init(jasonow->GetID(), coordinator);
}

void Map_1_Actors::Update(DWORD dt) {
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    std::shared_ptr<MovementSystem> movementSystem = coordinator->GetSystem<MovementSystem>(SystemType::Movement);
    animationSystem->Update();
    movementSystem->Update(dt);
}

void Map_1_Actors::Render() {
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    std::shared_ptr<SpriteSystem> spriteSystem = coordinator->GetSystem<SpriteSystem>(SystemType::Sprite);

    animationSystem->AnimationRender();
    spriteSystem->SpriteRender();
}