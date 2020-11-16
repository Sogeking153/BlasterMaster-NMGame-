#pragma once
/**
 * Sophia is splited into multiple parts
 * Each parts has their own id ( like a entity)
 * There is an invisible point. That point will be pivot to other parts of the car adjust their positions and stuff
 * 
 * */
class Coordinator;
class Sophia {
public:
    Sophia(Coordinator *);
    int GetID();
    void Test();
private:
    int entityID;

    //Parts of car
	int bodyID;
	int wheel1ID;
    int wheel2ID;
	int barrelID;
	int axelID;
};