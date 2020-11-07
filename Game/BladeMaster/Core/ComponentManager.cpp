#include "ComponentManager.h"
#include"../Component/PositionComponent.h"
#include"../Component/SpriteComponent.h"
#include"../Component/AnimationComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Component/BoundingBoxComponent.h"
ComponentManager::ComponentManager()
{
	RegisterComponent<Sprite>(ComponentType::Sprite);
	RegisterComponent<Position>(ComponentType::Position);
	RegisterComponent<Animation>(ComponentType::Animation);
	RegisterComponent<Velocity>(ComponentType::Speed);
	RegisterComponent<BoundingBox>(ComponentType::BoundingBox);

}
