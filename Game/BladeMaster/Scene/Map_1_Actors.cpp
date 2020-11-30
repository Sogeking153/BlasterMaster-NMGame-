#include "Map_1_Actors.h"
#include "../ECS_Entity_Ex/Sophia.h"
#include "../ECS_Entity_Ex/Jason.h"
#include "../ECS_Entity_Ex/JasonOW.h"
#include "../ECS_Entity_Ex/Bullet1.h"
#include "../System/AnimationSystem.h"
#include "../System/SpriteSystem.h"
#include "../System/MovementSystem.h"
#include "../System/PhysicSystem.h"
#include "../Core/Coordinator.h"
#include "../InputHandling/Core/InputContext.h"
#include "../HelperHeader/PlayerType.h"
#include "../Component/BoundingBoxComponent.h"
#include "../Camera.h"
#include <iostream>
#include <fstream>
#include <string>

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
    std::shared_ptr<PhysicSystem> physicSystem = coordinator->GetSystem<PhysicSystem>(SystemType::Physic);
    physicSystem->coordinator = coordinator;

    //sophia = new Sophia(coordinator);
    //Setup player
<<<<<<< Updated upstream
    jason = new Jason(coordinator);
    jasonow = new JasonOW(coordinator.get());
    //bullet1 = new Bullet1(coordinator);
=======
    /*jason = new Jason(coordinator);
    jasonow = new JasonOW(coordinator.get());*/

    LoadSections(L"Resources/Config/lvl2_sections.txt");

>>>>>>> Stashed changes
    //Setup Input
    InputContext* input = InputContext::GetInstance();
    input->coordinator = coordinator.get();
    input->player->currentPlayerType = PlayerType::SOPHIA;
    input->player->sophia = sophia;

    //Setup Camera
    Camera* camera = Camera::GetInstance();
    camera->Init(sophia->GetID(), coordinator);
}

void Map_1_Actors::Update(DWORD dt) {
    //Object Update
    sophia->Update(dt);

    //System Update
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    std::shared_ptr<MovementSystem> movementSystem = coordinator->GetSystem<MovementSystem>(SystemType::Movement);
    std::shared_ptr<PhysicSystem> physicSystem = coordinator->GetSystem<PhysicSystem>(SystemType::Physic);
  
    animationSystem->Update();
    movementSystem->Update(dt);
    physicSystem->Update(dt);
}

void Map_1_Actors::Render() {
    std::shared_ptr<AnimationSystem> animationSystem = coordinator->GetSystem<AnimationSystem>(SystemType::Animation);
    std::shared_ptr<SpriteSystem> spriteSystem = coordinator->GetSystem<SpriteSystem>(SystemType::Sprite);

    animationSystem->AnimationRender();
    spriteSystem->SpriteRender();
<<<<<<< Updated upstream
}

std::shared_ptr<Coordinator> Map_1_Actors::Get_coordinator()
{
    return coordinator;
=======

    animationSystem->RenderBoundingBox();
    spriteSystem->RenderBoundingBox();
}

void Map_1_Actors::LoadSections(LPCWSTR filePath)
{
	std::fstream input;
	input.open(filePath, std::ios::in);
	if (input.is_open()) {
		std::string str;
		char delimiter = '|';
		char skipChar = '#';
		while (std::getline(input, str)) {
			if (str[0] == skipChar) continue;
           
            std::string type;
            //String manipulation
            unsigned int current, previous = 0;
            current = str.find(delimiter);

            //TODO: reduce duplicate code
            while (current != std::string::npos) {
                type = str.substr(previous, current - previous);
                previous = current + 1;
                current = str.find(delimiter, previous);

                if (type == "PLAYER") {
                    int x, y;

                    x = std::stoi(str.substr(previous, current - previous));
                    previous = current + 1;
                    current = str.find(delimiter, previous);

                    y = std::stoi(str.substr(previous, current - previous));
                    previous = current + 1;
                    current = str.find(delimiter, previous);

                    sophia = new Sophia(coordinator, x, y);
                }
                if (type == "BRICK") {
                    Position pos;

                    pos.x = std::stoi(str.substr(previous, current - previous));
                    previous = current + 1;
                    current = str.find(delimiter, previous);

                    pos.y = std::stoi(str.substr(previous, current - previous));
                    previous = current + 1;
                    current = str.find(delimiter, previous);

                    EntityID brick = coordinator->CreateEntity();
                    coordinator->AddComponent<Position>(brick, pos, ComponentType::Position);
                    BoundingBox bbox;
                    bbox.left = pos.x;
                    bbox.right = pos.x + 32;
                    bbox.top = pos.y;
                    bbox.bottom = pos.y + 32;
                    coordinator->AddComponent<BoundingBox>(brick, bbox, ComponentType::BoundingBox);
                    coordinator->GetSystem<SpriteSystem>(SystemType::Sprite)->AddEntity(brick);
                    coordinator->GetSystem<PhysicSystem>(SystemType::Physic)->AddEntity(brick);
                }
            }
            
            
		}
		input.close();
    }
    else {
        DebugOut(L"[ERROR] Failed to open %s\n", filePath);
    }
>>>>>>> Stashed changes
}
