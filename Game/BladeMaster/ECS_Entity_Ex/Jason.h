#pragma once
#include <memory>
#include "../Component/SpeedComponent.h"
class Coordinator;


class Jason {
public:
	Jason(std::shared_ptr<Coordinator>);
	int GetID();
	void Test();
	void SwitchState(int);

public:
	enum {
		Idle_Left,
		Idle_Right,
		Walk_Left,
		Walk_Right,
		Crawl_Idle_Left,
		Crawl_Idle_Right,
		Crawl_Left,
		Crawl_Right,
		Climb,
		Jump_Left,
		Jump_Right,
	} currentState;
private:
	int entityID;
	Velocity jason_vel;
	
	std::shared_ptr<Coordinator> coordinator;
};
