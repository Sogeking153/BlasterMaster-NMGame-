#pragma once
#include"SystemBase.h"
#include"../Debug.h"
#include<unordered_map>
#include<memory>

enum class SystemType {
	Sprite = 0,
	Animation
};

class SystemManager
{
public:
	SystemManager();

	template<typename T>
	std::shared_ptr<SystemBase> GetSystem(SystemType type) {
		if (mSystems.find(type) == mSystems.end()) {
			DebugOut(L"System not found");
			return nullptr;
		}

		return mSystems[type];
	}

	void EntityDestroyed(EntityID entityID) {
		for (auto const& iterator : mSystems) {
			std::shared_ptr<SystemBase>  const& system = iterator.second;
			system->mEntityList.erase(entityID);
		}
	}
private:
	std::unordered_map<SystemType, std::shared_ptr<SystemBase>> mSystems;
};

