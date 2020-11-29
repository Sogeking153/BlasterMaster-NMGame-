#include "Camera.h"
#include "EventHandler/CameraSwitchModeEvent.h"
#include "EventHandler/EventHandling.h"
#include "HelperHeader/stdafx.h"
#include "Core/Coordinator.h"
#include "HelperHeader/Debug.h"
#include "Component/PositionComponent.h"
Camera* Camera::__instance = NULL;
void Camera::Update()
{
	switch (currentMode)
	{
	case Mode::X_AXIS:
		UpdateMode0();
		break;
	case Mode::PLATFORM_LOCKED:
		UpdateMode1();
		break;
	case Mode::Y_AXIS:
		UpdateMode2();
		break;
	case Mode::XY_AXIS:
		UpdateMode3();
		break;
	default:
		break;
	}
}

void Camera::SwitchMode(const CameraSwitchModeEvent * event)
{
	this->currentMode = (Mode)event->newCameraType;
}

bool Camera::isWithinCamera(RECT size,float x, float y, bool isOverlapped)
{
	float fFrustum_Left = isOverlapped ? this->x - size.right : this->x;
	float fFrustum_Right = isOverlapped ? (this->x + WINDOW_WIDTH + size.right) : (this->x + WINDOW_WIDTH);
	float fFrustum_Top = isOverlapped ? this->y - size.bottom : this->y;
	float fFrustum_Bottom = isOverlapped ? (this->y + WINDOW_HEIGHT + size.bottom) : (this->y + WINDOW_HEIGHT);

	if (x >= fFrustum_Left         // Within left side of frustum
		&& (x + size.right) <= fFrustum_Right    // Within right side of frustum
		&& y >= fFrustum_Top        // Below top side of frustum
		&& (y + size.bottom) <= fFrustum_Bottom) // Above bottom of frustum
	{
		// Collider is inside camera frustum
		return true;
	}

	// Collider is outside camera frustum
	return false;
}

void Camera::Init(int playerID, std::shared_ptr<Coordinator> coordinator)
{
	//Setup event handling
	EventHandling* eventHandler = EventHandling::GetInstance();
	eventHandler->registerEventFunction<Camera, CameraSwitchModeEvent>(this, &Camera::SwitchMode);
	
	//Setup variables
	currentMode = Mode::X_AXIS;
	this->playerID = playerID;
	this->coordinator = coordinator;

	//Setup default position
	Position playerPos = coordinator->GetComponent<Position>(playerID, ComponentType::Position);
	x = playerPos.x - WINDOW_WIDTH / 2;
	y = playerPos.y - WINDOW_HEIGHT / 2;
}

Camera* Camera::GetInstance()
{
	if (__instance == nullptr) __instance = new Camera();
	return __instance;
}

void Camera::UpdateMode0()
{
	if (coordinator == nullptr)
	{
		DebugOut(L"[ERROR] Coordinator in Camera is null");
		return;
	}

	Position playerPos = coordinator->GetComponent<Position>(playerID, ComponentType::Position);
	x = playerPos.x - WINDOW_WIDTH / 2;
}

/*
	Don't know how to implement yet
*/
void Camera::UpdateMode1()
{
	if (coordinator == nullptr)
	{
		DebugOut(L"[ERROR] Coordinator in Camera is null");
		return;
	}
}

void Camera::UpdateMode2()
{
	if (coordinator == nullptr)
	{
		DebugOut(L"[ERROR] Coordinator in Camera is null");
		return;
	}

	Position playerPos = coordinator->GetComponent<Position>(playerID, ComponentType::Position);
	y = playerPos.y - WINDOW_HEIGHT / 2;
}

void Camera::UpdateMode3()
{
	if (coordinator == nullptr)
	{
		DebugOut(L"[ERROR] Coordinator in Camera is null");
		return;
	}
}
