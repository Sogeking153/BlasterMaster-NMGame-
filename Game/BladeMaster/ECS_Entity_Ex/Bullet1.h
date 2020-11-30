#pragma once
#include <memory>
#include "../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../Component/PositionComponent.h"
class Coordinator;

class Bullet1
{
public:
	Bullet1(Coordinator*, Position, Direction);
	int GetID();
	void Test();
private:
	int entityID;

	std::shared_ptr<Coordinator> coordinator;
};

