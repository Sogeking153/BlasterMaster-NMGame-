#include "SpriteSystem.h"
#include "../Engine.h"
#include "../Core/Coordinator.h"
#include"../Component/SpriteComponent.h"
#include "../Component/PositionComponent.h"
#include "../TextureDatabase.h"
#include "../SpriteDatabase.h"

extern Coordinator coordinator;

SpriteSystem::SpriteSystem()
{
	Bitmask requirement;
	requirement.set((int)ComponentType::Position, true);
	requirement.set((int)ComponentType::Sprite, true);
	mRequiredComponents.push_back(requirement);
}

void SpriteSystem::SpriteRender()
{
	LPD3DXSPRITE spriteHandler = Engine::GetInstance()->GetSpriteHandler();
	TextureDatabase* textureDb = TextureDatabase::GetInstance();
	SpriteDatabase* spriteDb = SpriteDatabase::GetInstance();
	for (EntityID const& entity : mEntityList) {

		Sprite& sprite = coordinator.GetComponent<Sprite>(entity, ComponentType::Sprite);
		Position& position = coordinator.GetComponent<Position>(entity, ComponentType::Position);
		std::shared_ptr<TextureData> texture = textureDb->GetTexture((TextureID)sprite.textureID);
		RECT r = spriteDb->GetSprite(sprite.textureID, sprite.spriteID);
		D3DXVECTOR3 p(position.x, position.y, 0);

		spriteHandler->Draw(texture->texture, &r , NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
	}
	
}

