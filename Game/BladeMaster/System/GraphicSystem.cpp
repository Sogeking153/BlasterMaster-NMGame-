#include "GraphicSystem.h"
#include "../Core/Coordinator.h"
#include "../Component/BoundingBoxComponent.h"
#include "../Component/PositionComponent.h"
#include "../TextureDatabase.h"
#include "../Engine.h"
#include "../Camera.h"

GraphicSystem::GraphicSystem()
{
	Bitmask requirement;
	requirement.set((int)ComponentType::Position, true);
	requirement.set((int)ComponentType::BoundingBox, true);
	mRequiredComponents.push_back(requirement);
}

void GraphicSystem::RenderBoundingBox()
{
	LPD3DXSPRITE spriteHandler = Engine::GetInstance()->GetSpriteHandler();
	TextureDatabase* textureDb = TextureDatabase::GetInstance();
	Camera* camera = Camera::GetInstance();
	for (EntityID const& entity : mEntityList) {
		if ((coordinator->GetEntityBitmask(entity) & mRequiredComponents[0]) != mRequiredComponents[0]) continue;
		Position& position = coordinator->GetComponent<Position>(entity, ComponentType::Position);
		std::shared_ptr<TextureData> texture = textureDb->GetTexture(TEXTURE_BOUNDING_BOX_ID);
		D3DXVECTOR3 p(position.x - camera->x, position.y - camera->y, 0);

		BoundingBox bbox = coordinator->GetComponent<BoundingBox>(entity, ComponentType::BoundingBox);

		RECT r;
		r.left = 0;
		r.right = bbox.right - bbox.left;
		r.top = 0;
		r.bottom = bbox.bottom - bbox.top;

		spriteHandler->Draw(texture->texture, &r, NULL, &p, D3DCOLOR_ARGB(100,255, 255, 255));
	}
}
