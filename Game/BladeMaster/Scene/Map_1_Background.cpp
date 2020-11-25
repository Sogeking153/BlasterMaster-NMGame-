#include "Map_1_Background.h"
#include "../Core/Coordinator.h"
#include "../Component/PositionComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Component/AnimationComponent.h"
#include "../System/SpriteSystem.h"
#include "../HelperHeader/UtilHeader.h"
#include <fstream>
#include <iostream>

extern Coordinator coordinator;

Map_1_Background::Map_1_Background(short id)
{
    this->id = id;
	coordinator = std::make_unique<Coordinator>();
	std::shared_ptr<SpriteSystem> spriteSystem = coordinator->GetSystem<SpriteSystem>(SystemType::Sprite);
	spriteSystem->coordinator = coordinator;
	int number;
	int tempcount = 0;
	Position posTile[17000];
	Sprite spriteTile[17000];
	int rowNumber = 0;
	int colNumber = 0;

	std::ifstream inFile;

	inFile.open("Resources/Config/lvl2_side_tilemap.txt");
	//inFile.open("test.txt");
	if (!inFile)
	{
		DebugOut(L"[ERROR] Unable to open file");
		exit(1);
	}

	while (inFile >> number)
	{

		tilemap[tempcount] = coordinator->CreateEntity();
		spriteTile[tempcount].textureID = TILE_MAP;
		spriteTile[tempcount].spriteID = number;
		coordinator->AddComponent(tilemap[tempcount], spriteTile[tempcount], ComponentType::Sprite);

		posTile[tempcount].x = colNumber * 16;
		posTile[tempcount].y = rowNumber * 16;
		coordinator->AddComponent(tilemap[tempcount], posTile[tempcount], ComponentType::Position);
		spriteSystem->AddEntity(tilemap[tempcount]);
		colNumber++;

		tempcount++;

		if (colNumber == 129)
		{
			colNumber = 0;
			rowNumber++;
		}
	}

	inFile.close();

	
}

void Map_1_Background::Update(DWORD dt)
{

}

void Map_1_Background::Render()
{
	std::shared_ptr<SpriteSystem> spriteSystem = coordinator->GetSystem<SpriteSystem>(SystemType::Sprite);
	spriteSystem->SpriteRender();
}


