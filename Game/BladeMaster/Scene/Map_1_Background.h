#pragma once
#include "SceneBase.h"
#include <memory>
/*
	This class's sole purepose is render background of world 1
*/
class Coordinator;
class Map_1_Background : public SceneBase {
public:
	Map_1_Background(){}
	Map_1_Background(short id);
	// Inherited via SceneBase
	virtual void Update(DWORD dt) override;
	virtual void Render() override;

private:
	int tilemap[17000];
	//int gunner;
	std::shared_ptr<Coordinator> coordinator;
};