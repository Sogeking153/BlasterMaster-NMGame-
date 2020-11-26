#pragma once
#include "EventBase.h"
class CameraSwitchModeEvent : public Event
{
public:
	short newCameraType; //Don't want to include Camera.h here. So anyone wants to use this needs to converse to enum type
};

