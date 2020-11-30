#pragma once
#include "SceneBase.h"
#include "Section/Grid.h"
#include<memory>
#include<vector>
class Sophia;
class Jason;
class JasonOW;
class Coordinator;
class Map_1_Actors : public SceneBase {
public: 
    Map_1_Actors() {}
    Map_1_Actors(short id);
    void Update(DWORD dt);
    void Render();
    std::shared_ptr<Coordinator> Get_coordinator();
private:
    void LoadSections(LPCWSTR path);
private:
    Sophia * sophia;
    Jason * jason;
    JasonOW* jasonow;
    std::shared_ptr<Coordinator> coordinator;

    Grid grid;
};