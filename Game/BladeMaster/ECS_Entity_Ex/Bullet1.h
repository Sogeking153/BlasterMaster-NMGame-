#pragma once
#include <memory>
#include "../Component/SpeedComponent.h"
class Coordinator;

class Bullet1
{
public:
	Bullet1(std::shared_ptr<Coordinator>);
	int GetID();
	void Test();
private:
	int entityID;
	Velocity bullet_vel;

	std::shared_ptr<Coordinator> coordinator;
};

