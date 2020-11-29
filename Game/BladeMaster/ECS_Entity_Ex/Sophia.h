#pragma once
#include <memory>
#include "../Component/SpeedComponent.h"
#include "../Component/PositionComponent.h"
/**
 * Sophia is splited into multiple parts
 * Each parts has their own id ( like a entity)
 * There is an invisible point. That point will be pivot to other parts of the car adjust their positions and stuff
 * 
 * */
class Coordinator;
class Sophia {
public:
    Sophia(std::shared_ptr<Coordinator>);
    int GetID();
    void Test();
    void SwitchState(int);
    void PartPosUpdate();
public:
    enum 
    {
        Bait,
        Idle_Left,
        Idle_Right,
        Go_Left,
        Go_Right,
        Right_To_Left,
        Left_To_Right,
    } currentState;
private:
    int entityID;

    //Parts of car
	int bodyID;
	int wheel1ID;
    int wheel2ID;
	int barrelID;
	int axelID;

    std::shared_ptr<Coordinator> coordinator;
};