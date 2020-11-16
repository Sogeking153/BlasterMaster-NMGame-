#include "SystemManager.h"
#include "../System/SpriteSystem.h"
#include "../System/AnimationSystem.h"
SystemManager::SystemManager()
{
	mSystems.insert({ SystemType::Sprite, std::make_shared<SpriteSystem>() });
	mSystems.insert({ SystemType::Animation, std::make_shared<AnimationSystem>() });

}
