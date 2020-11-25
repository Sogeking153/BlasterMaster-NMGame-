#pragma once
#include "SceneBase.h"

/*
	This scene is solely for testing physic purpose and WILL NOT BE included in final product
*/
class Physics_scene : public SceneBase {
public:
	Physics_scene() {}
	Physics_scene(short id);
	// Inherited via SceneBase
	virtual void Update(DWORD dt) override;
	virtual void Render() override;
};