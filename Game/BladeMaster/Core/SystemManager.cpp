#include "SystemManager.h"
#include "../System/SpriteSystem.h"
#include "../System/AnimationSystem.h"
#include "../System/MovementSystem.h"
SystemManager::SystemManager()
{
	mSystems.insert({ SystemType::Sprite, std::make_shared<SpriteSystem>() });
	mSystems.insert({ SystemType::Animation, std::make_shared<AnimationSystem>() });
	mSystems.insert({ SystemType::Movement, std::make_shared<MovementSystem>() });

}
