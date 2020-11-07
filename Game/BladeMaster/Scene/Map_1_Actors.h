#pragma once
#include "SceneBase.h"

class Map_1_Actors : public SceneBase {
public: 
    Map_1_Actors() {}
    Map_1_Actors(short id);
    void Update(DWORD dt);
    void Render();
};