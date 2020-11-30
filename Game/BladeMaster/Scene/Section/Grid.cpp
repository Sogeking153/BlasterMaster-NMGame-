#include "Grid.h"

Grid::Grid()
{
	for (int i = 0; i < MAX_CELLS; i++) {
		for (int j = 0; j < MAX_CELLS; j++)
		{
			cells[i][j] = nullptr;
		}
	}
}

void Grid::AddEntity(int EntityID, float x, float y) {
	//Determine which cell that entity will go to
	int row = (int)(y / CELL_SIZE);
	int column = (int)(x / CELL_SIZE);

	if (row > MAX_CELLS || column > MAX_CELLS) {
		DebugOut(L"[ERROR] this entity with id %d don't belong to this region\nrow: %d\ncolumn: %d\n", EntityID, row, column);
		return;
	}

	Node * n = new Node();
	n->entityID = EntityID;

	// Add to the front of list for the cell it's in.
	n->prev = nullptr;
	n->next = cells[row][column];
	cells[row][column] = n;

	if (n->next != nullptr)
		n->next->prev = n;
}

void Grid::ClearGrid() {
	for (int i = 0; i < MAX_CELLS; i++) {
		for (int j = 0; j < MAX_CELLS; j++)
		{
			delete cells[i][j];
		}
	}
}

void Grid::UpdateEntity(int EntityID, float old_x, float old_y, float new_x, float new_y)
{
	// See which cell it was in.
	int oldCellX = (int)(old_x / CELL_SIZE);
	int oldCellY = (int)(old_y / CELL_SIZE);

	// See which cell it's moving to.
	int cellX = (int)(new_x / CELL_SIZE);
	int cellY = (int)(new_y / CELL_SIZE);

	if (oldCellX == cellX && oldCellY == cellY) return;

	// Find the right node
	Node* movedEntity = cells[oldCellX][oldCellY];
	while (movedEntity != nullptr) {
		if (movedEntity->entityID == EntityID) {
			break;
		}
		else {
			movedEntity = movedEntity->next;
		}
	}

	// Unlink it from the list of its old cell.
	
	if (movedEntity->prev != nullptr) {
		movedEntity->prev->next = movedEntity->next;
	}
	if (movedEntity->next != nullptr) {
		movedEntity->next->prev = movedEntity->prev;
	}

	// If it's the head of a list, remove it.
	if (cells[oldCellX][oldCellY] == movedEntity) {
		cells[oldCellX][oldCellY]->next = movedEntity->next;
	}

	// Add it back to the grid at its new cell.
	movedEntity->prev = nullptr;
	movedEntity->next = cells[cellX][cellY];
	cells[cellX][cellY] = movedEntity;

	if (movedEntity->next != nullptr)
		movedEntity->next->prev = movedEntity;
}
