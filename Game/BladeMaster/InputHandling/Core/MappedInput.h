#pragma once
#include <dinput.h>

struct MappedInput {
  BYTE  keyStates[256];
	
  //Data for key buffered event
  int KeyCode = -1;
  int KeyData = -1;
};
