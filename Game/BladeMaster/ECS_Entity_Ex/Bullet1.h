#pragma once
#include <memory>
#include "../Component/SpeedComponent.h"
#include "../Component/DirectionComponent.h"
#include "../Component/PositionComponent.h"
class Coordinator;

class Bullet1
{
public:
	Bullet1(Coordinator*, Position, Direction); //int bullet_type
	int GetID();
	void Test(); //int Get_bullet_type()
private:
	int entityID;

	std::shared_ptr<Coordinator> coordinator;
};

