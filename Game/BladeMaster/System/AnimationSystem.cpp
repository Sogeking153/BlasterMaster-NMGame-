#include "AnimationSystem.h"
#include "../Core/Coordinator.h"
#include "../Component/AnimationComponent.h"
#include "../Component/PositionComponent.h"
#include "../TextureDatabase.h"
#include "../SpriteDatabase.h"
#include "../Engine.h"

extern Coordinator coordinator;
AnimationSystem::AnimationSystem() {
    Bitmask requirement;
    requirement.set((int)ComponentType::Animation, true);
	requirement.set((int)ComponentType::Position, true);
	mRequiredComponents.push_back(requirement);
}

void AnimationSystem::AnimationRender() {
    LPD3DXSPRITE spriteHandler = Engine::GetInstance()->GetSpriteHandler();
	TextureDatabase* textureDb = TextureDatabase::GetInstance();
	for (EntityID const& entity : mEntityList) {
		//Check if this entity has Animation component
		if ((coordinator.GetEntityBitmask(entity) & mRequiredComponents[1]) != mRequiredComponents[1]) continue;

		Animation& animation = coordinator.GetComponent<Animation>(entity, ComponentType::Animation);
		Position& position = coordinator.GetComponent<Position>(entity, ComponentType::Position);
		std::shared_ptr<TextureData> texture = textureDb->GetTexture((TextureID)animation.textureID);
		D3DXVECTOR3 p(position.x, position.y, 0);
		RECT r;
		r.left = animation.currentFrame % texture->columns * texture->size_width;
		r.top = animation.currentFrame % texture->rows * texture->size_height;
		r.right = animation.currentFrame % texture->columns * texture->size_width + texture->size_width;
		r.bottom = animation.currentFrame % texture->rows * texture->size_height + texture->size_height;
		spriteHandler->Draw(texture->texture, &r, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void AnimationSystem::Update() {
    DWORD now = GetTickCount();
	for (EntityID const& entity : mEntityList) {
		Animation& animation = coordinator.GetComponent<Animation>(entity, ComponentType::Animation);

		if (now - animation.animationCounter > animation.delayValue && animation.isFinished == false) {
			animation.currentFrame++;
			animation.animationCounter = now;
			if (animation.currentFrame == animation.stateDictionary[animation.currentState].endFrame + 1) {
				if (animation.stateDictionary[animation.currentState].isLoopable) {
					animation.currentFrame = animation.stateDictionary[animation.currentState].startFrame;
				}
				else {
					animation.isFinished = true;
					animation.currentState = StateID::Idle;
				}

			}
		}


	}
}