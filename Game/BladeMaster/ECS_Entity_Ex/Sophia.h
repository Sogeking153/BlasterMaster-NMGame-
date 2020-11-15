#pragma once
class Coordinator;
class Sophia {
public:
    Sophia(Coordinator *);
    int GetID();
private:
    int entityID;

    //Parts of car
	int bodyID;
	int wheel1ID;
    int wheel2ID;
	int barrelID;
	int axelID;
};