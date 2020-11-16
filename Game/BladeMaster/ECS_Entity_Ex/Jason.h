#pragma once
class Coordinator;
class Jason {
public:
	Jason(Coordinator*);
	Jason();
	int GetID();
	void Test();
private:
	int entityID;

	
};
