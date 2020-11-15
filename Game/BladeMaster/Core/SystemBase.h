#pragma once
#include"Type.h"
#include<set>
#include<vector>
#include <memory>
using Requirements = std::vector<Bitmask>;
class Coordinator;
class SystemBase
{
public:
	void AddEntity(EntityID);
	void RemoveEntity(EntityID);
public:
	std::set<EntityID> mEntityList;
	Requirements mRequiredComponents;
	std::shared_ptr<Coordinator> coordinator;
};

