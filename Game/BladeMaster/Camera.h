#pragma once
#include <memory>
#include <d3d9.h>
/*
	The camera will have 4 mode: (I use Super Mario World's camera technique)
		0. Disable vertical scroll entirely 
		1. Platform locked
		2. Locks the vertical scroll to the bottom of the screen
		3. Disable both vertical and horizontal scroll

	In mode 1, the game keeps track of "ground level" at whatever platform you've lasted landed on. Heading downwards below ground level you scroll freely.
	Heading upwards there is no scrolling until you land on a platform, which will scroll up and set ground level

	In mode 2, the game will refuse to vertically scroll from the bottom level unless you do something that enable free scrolling. The "no vertical scrolling" rule
	only applies on the bottom, so it is functionally Mode 1 if the level doesn't touch the bottom, so levels hugging the celling won't scrolling much

	Link: https://www.reddit.com/r/gamedev/comments/lrewu/super_mario_world_camera_logic_review/

	To handle transitioning between camera modes I makes some new entities for my game world. I add invinsible trigger can be placed as a game object in a level.
	Each side of trigger, the trigger can be horizontal or vertical, has an associated camera type that will be switch to based on the direction of the player

	Link: https://tl.net/blogs/396594-game-programming-the-camera#	


*/
/*
	Camera

	void Update() -> Interface to use. In this function, there are 4 Update function corresponding to 4 Mode
	void UpdateMode0() -> Update camera position with mode 0's constraint
	void UpdateMode1() -> Update camera position with mode 1's constraint
	void UpdateMode2() -> Update camera position with mode 2's constraint
	void UpdateMode3() -> Update camera position with mode 3's constraint

	void SwitchMode(Event * event) -> handling switch camera's mode event when player collide with trigger
	bool isWithinCamera(RECT r, bool isOverlapped) -> Decide whether an object is within camera. The flag determines whether we want to 
													allow the collider to be PARTIALLY (overlapping) inside the frustum, in which case we 
													would pass ‘true‘, or whether we want to make sure the collider is ENTIRELY inside 
													the frustum, in which case we would pass ‘false‘. This function is intented for background 
													only
													Link: https://lcmccauley.wordpress.com/2014/04/27/2d-frustum-culling-tutorial-p2/


*/
class Event;
class CameraSwitchModeEvent;
class Coordinator;

class Camera
{
public:
	void Update();
	void SwitchMode(const CameraSwitchModeEvent * event);
	bool isWithinCamera(RECT size, float x, float y, bool isOverlapped);
	void Init(int playerID, std::shared_ptr<Coordinator> coordinator);
	static Camera* GetInstance();
private:
	void UpdateMode0();
	void UpdateMode1();
	void UpdateMode2();
	void UpdateMode3();
public:
	enum class Mode {
		X_AXIS, //Camera will locked vertical scrolling
		PLATFORM_LOCKED, // Read comment above :D
		Y_AXIS, //Camera will locked horizontal scrolling
		XY_AXIS //Camera will locked both vertical and horizontal scrolling
	};
	Mode currentMode;

	float x;
	float y;

	int playerID;
	static Camera* __instance;
	std::shared_ptr<Coordinator> coordinator;
};

