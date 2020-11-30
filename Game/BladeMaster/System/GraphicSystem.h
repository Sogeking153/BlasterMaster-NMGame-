#pragma once
#include "../Core/SystemBase.h"
/*
* This class purpose is to have a RenderBoundingBox function
* Both Animation System and Graphic System will inherit from this
*/
#define TEXTURE_BOUNDING_BOX_ID 23
class GraphicSystem : public SystemBase {
public:
	GraphicSystem();
	void RenderBoundingBox();
};