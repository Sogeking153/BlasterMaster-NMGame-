#pragma once
#include "../ECS_Entity_Ex/Jason.h"
#include "../ECS_Entity_Ex/Sophia.h"
struct PlayerType {
    enum { SOPHIA, JASON } currentPlayerType;
    union {
        Sophia* sophia;
        Jason* jason;
    };
};
