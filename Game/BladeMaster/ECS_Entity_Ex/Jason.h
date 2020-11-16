#pragma once
#include <memory>
class Coordinator;

class Jason {
public:
	Jason(std::shared_ptr<Coordinator>);
	int GetID();
	void Test();
	void SwitchState(int);
private:
	int entityID;
	enum {
		Idle,
		Walk,
		Crawl,
		Climb
	} currentAnimation;
	std::shared_ptr<Coordinator> coordinator;
};
