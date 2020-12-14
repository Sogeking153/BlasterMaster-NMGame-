#include "MovementSystem.h"
#include "../Core/Coordinator.h"
#include "../EventHandler/PhysicEvent.h"
#include "../EventHandler/EventHandling.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../HelperHeader/UtilHeader.h"
MovementSystem::MovementSystem()
{
	Bitmask requirement;
	requirement.set((int)ComponentType::Speed, true);
	requirement.set((int)ComponentType::Position, true);
	requirement.set((int)ComponentType::Direction, true);
	mRequiredComponents.push_back(requirement);

	//Register PhysicEvent
	EventHandling* eventHandling = EventHandling::GetInstance();
	eventHandling->registerEventFunction<MovementSystem, CollisionEvent>(this, &MovementSystem::onEvent);
}

void MovementSystem::onEvent(const CollisionEvent * _event)
{
	//Position& pos = coordinator->GetComponent<Position>(_event->entityID, ComponentType::Position);
	//Velocity & speed = coordinator->GetComponent<Velocity>(_event->entityID, ComponentType::Speed);


	//
	//for (UINT i = 0; i < _event->coEventResult.size(); i++) {

	//}
}

void MovementSystem::Update(DWORD dt)
{
	for (EntityID const & entity : mEntityList) {
		Position& pos = coordinator->GetComponent<Position>(entity, ComponentType::Position);
		Velocity& speed = coordinator->GetComponent<Velocity>(entity, ComponentType::Speed);
		Direction & dir = coordinator->GetComponent<Direction>(entity, ComponentType::Direction);

		//simple gravity but need fixing
		/*if (pos.y < 64)
		{
			speed.vy = GRAVITY;
		}
		else if (pos.y > 64)
		{
			speed.vy = 0;
			pos.y = 64;
		}*/

		speed.dx =  dir.nx * speed.vx * dt;
		speed.dy = dir.ny* speed.vy * dt;

		pos.x += speed.dx;
		pos.y += speed.dy;

	}
}
