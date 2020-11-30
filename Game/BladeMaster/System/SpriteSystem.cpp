#include "SpriteSystem.h"
#include "../Engine.h"
#include "../Core/Coordinator.h"
#include"../Component/SpriteComponent.h"
#include "../Component/PositionComponent.h"
#include "../Component/TransformationComponent.h"
#include "../TextureDatabase.h"
#include "../SpriteDatabase.h"
#include "../Camera.h"
SpriteSystem::SpriteSystem()
{
	Bitmask requirement;
	requirement.set((int)ComponentType::Position, true);
	requirement.set((int)ComponentType::Sprite, true);
	mRequiredComponents.push_back(requirement);
	
	requirement.set((int)ComponentType::Transformation, true);
	mRequiredComponents.push_back(requirement);
}

void SpriteSystem::SpriteRender()
{
	LPD3DXSPRITE spriteHandler = Engine::GetInstance()->GetSpriteHandler();
	TextureDatabase* textureDb = TextureDatabase::GetInstance();
	SpriteDatabase* spriteDb = SpriteDatabase::GetInstance();
	Camera* camera = Camera::GetInstance();
	for (EntityID const& entity : mEntityList) {
		if ((coordinator->GetEntityBitmask(entity) & mRequiredComponents[2]) == mRequiredComponents[2]) {
			Sprite& sprite = coordinator->GetComponent<Sprite>(entity, ComponentType::Sprite);
			Position& position = coordinator->GetComponent<Position>(entity, ComponentType::Position);
			RECT r = spriteDb->GetSprite(sprite.textureID, sprite.spriteID);

			if (camera->isWithinCamera(r, position.x, position.y, true) == false) continue;

			std::shared_ptr<TextureData> texture = textureDb->GetTexture((TextureID)sprite.textureID);
			D3DXVECTOR3 p(position.x - camera->x, position.y - camera->y, 0);

			D3DXMATRIX mat;
			Transformation transformMatrix = coordinator->GetComponent<Transformation>(entity, ComponentType::Transformation);
			spriteHandler->GetTransform(&mat);
			spriteHandler->SetTransform(&transformMatrix.transformMatrix);
			spriteHandler->Draw(texture->texture, &r, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));

			spriteHandler->SetTransform(&mat);
			continue;
		}

		if((coordinator->GetEntityBitmask(entity) & mRequiredComponents[1]) == mRequiredComponents[1]) {
			Sprite& sprite = coordinator->GetComponent<Sprite>(entity, ComponentType::Sprite);
			Position& position = coordinator->GetComponent<Position>(entity, ComponentType::Position);
			RECT r = spriteDb->GetSprite(sprite.textureID, sprite.spriteID);

			if (camera->isWithinCamera(r, position.x, position.y, true) == false) continue;

			std::shared_ptr<TextureData> texture = textureDb->GetTexture((TextureID)sprite.textureID);
			D3DXVECTOR3 p(position.x - camera->x, position.y - camera->y, 0);

			spriteHandler->Draw(texture->texture, &r, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
			continue;
		}
		
	}
	
}

