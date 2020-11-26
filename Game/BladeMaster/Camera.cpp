#include "Camera.h"
#include "EventHandler/CameraSwitchModeEvent.h"
#include "EventHandler/EventHandling.h"
#include "HelperHeader/stdafx.h"
#include "Core/Coordinator.h"
#include "HelperHeader/Debug.h"
#include "Component/PositionComponent.h"
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

void Camera::Init(int playerID, std::shared_ptr<Coordinator> coordinator)
{
	//Setup event handling
	EventHandling* eventHandler = EventHandling::GetInstance();
	eventHandler->registerEventFunction<Camera, CameraSwitchModeEvent>(this, &Camera::SwitchMode);
	
	//Setup variables
	currentMode = Mode::Y_AXIS;
	this->playerID;
	this->coordinator = coordinator;

	//Setup default position
	Position playerPos = coordinator->GetComponent<Position>(playerID, ComponentType::Position);
	x = playerPos.x - WINDOW_WIDTH / 2;
	y = playerPos.y - WINDOW_HEIGHT / 2;
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
