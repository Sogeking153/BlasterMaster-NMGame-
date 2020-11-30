#pragma once
#include "SceneBase.h"
#include<memory>
class Sophia;
class Jason;
class JasonOW;
class Bullet1;
class Coordinator;
class Map_1_Actors : public SceneBase {
public: 
    Map_1_Actors() {}
    Map_1_Actors(short id);
    void Update(DWORD dt);
    void Render();

private:
    Sophia * sophia;
    Jason * jason;
    JasonOW* jasonow;
    Bullet1* bullet1;
    std::shared_ptr<Coordinator> coordinator;
};