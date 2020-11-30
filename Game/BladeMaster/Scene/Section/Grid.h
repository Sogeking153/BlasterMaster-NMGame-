#pragma once
#include "../../HelperHeader/Debug.h"
#include <memory>
/*
* Player won't belong to Grid and Player can interact with grid 
* We'll hardcode number of cells in a grid
* 
* Link: https://gameprogrammingpatterns.com/spatial-partition.html
*/
#define MAX_CELLS 100
#define CELL_SIZE 32
struct Node {
	Node* next = nullptr;
	Node* prev = nullptr;
	int entityID = -1;
};
class Grid {
public:
	Grid();
	void AddEntity(int EntityID, float x, float y);
	void ClearGrid();
	void UpdateEntity(int EntityID, float old_x, float old_y, float new_x, float new_y); // This function will be used in Movement System

private:
	Node* cells[MAX_CELLS][MAX_CELLS];
};