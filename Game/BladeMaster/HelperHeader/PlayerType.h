#pragma once
#include "../ECS_Entity_Ex/Jason.h"
#include "../ECS_Entity_Ex/Sophia.h"
#include "../ECS_Entity_Ex/JasonOW.h"
struct PlayerType {
    enum { SOPHIA, JASON, JASONOW} currentPlayerType;
    union {
        Sophia* sophia;
        Jason* jason;
        JasonOW* jasonow;
    };
};
