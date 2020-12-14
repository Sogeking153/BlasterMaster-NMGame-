#pragma once
#include <memory>
#include <d3d9.h>
#include "../Component/SpeedComponent.h"
#include "../Component/PositionComponent.h"
/**
 * Sophia is splited into multiple parts
 * Each parts has their own id ( like a entity)
 * There is an invisible point. That point will be pivot to other parts of the car adjust their positions and stuff
 * 
 * */
#define SOPHIA_BBOX_WIDTH 18
#define SOPHIA_BBOX_HEIGHT 18
class Coordinator;
class Sophia {
public:
    Sophia(std::shared_ptr<Coordinator>, int x, int y);
    int GetID();
    void SwitchState(int);
    void PartPosUpdateLeft();
    void PartPosUpdateRight();
    void PartPosUpdateAimUpLeft();
    void PartPosUpdateAimUpRight();
    void PartPosUpdateDownLeft();
    void PartPosUpdateDownRight();
    void PartPosUpdateJumpLeft();
    void PartPosUpdateJumpRight();
    void PartPosUpdateLandLeft();
    void PartPosUpdateLandRight();
    void PartPosUpdateEjectLeft();
    void PartPosUpdateEjectRight();
    void BaitLeft();

    void Update(DWORD dt);

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
        Body_Shift_Right,
        Body_Shift_Left,
        Jump_Left,
        Jump_Right,
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