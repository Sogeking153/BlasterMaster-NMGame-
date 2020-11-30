#pragma once
#include "GraphicSystem.h"
#include <d3d9.h>
#include <d3dx9.h>

//This is a system belong to ECS
/*
	This system is supposed to render everything related to graphic
	It can render sprite
	For an entity to be qualified to use this system, it must have:
		-> sprite component
		-> position component

	More information about sprite, SpriteComponent.h
	
*/
class SpriteSystem : public GraphicSystem {
public:
	SpriteSystem();
	void SpriteRender();
};
