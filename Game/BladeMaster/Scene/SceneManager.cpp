#include "SceneManager.h"
#include "SceneBase.h"
#include "../HelperHeader/Debug.h"
#include "../HelperHeader/UtilHeader.h"
#include "Map_1_Background.h"
#include "Map_1_Actors.h"
#include <thread>
SceneManager * SceneManager::__instance = NULL;

SceneManager::SceneManager()
{
    
}


void SceneManager::AddScene(SceneID id)
{
    SceneBase* newScene = createScene(id);
    mCurrentScenes.push_back(newScene);
}

//Error-prone. Need to test carefully
bool SceneManager::SwapScene(SceneID swapedID, SceneID swappingID)
{
    //find the scene
    for (int i = 0; i < mCurrentScenes.size(); i++) {
        if (mCurrentScenes[i]->getID() == swapedID) {
            SceneBase* newScene = createScene(swappingID);
            SceneBase* temp = mCurrentScenes[i];
            mCurrentScenes[i] = newScene;
            delete temp;
            return true;
        }
    }
    return false;
}

void SceneManager::RemoveScene(SceneID id)
{
    for (int i = 0; i < mCurrentScenes.size(); i++) {
        if (mCurrentScenes[i]->getID() == id)
            delete mCurrentScenes[i];
        //I'm not sure about this. Must testing carefully
        mCurrentScenes.erase(mCurrentScenes.begin() + i); 
        break;
    }
}

void SceneManager::RemoveAllScene()
{
    for (int i = 0; i < mCurrentScenes.size(); i++) {
        delete mCurrentScenes[i];
    }
}

void SceneManager::Update(DWORD dt)
{
    std::vector <std::thread> threads;
    //Update from back to font
    for (int i = mCurrentScenes.size() - 1; i >= 0; i--) {
        threads.push_back(std::thread(&SceneBase::Update, mCurrentScenes[i], dt));
        //mCurrentScenes[i]->Update(dt);
    }

    for (int i = 0; i < threads.size(); i++) threads[i].join();
}

void SceneManager::Render()
{
    //Render from back to font
    for (int i = mCurrentScenes.size() - 1; i >= 0; i--) {
        mCurrentScenes[i]->Render();
    }
}

SceneManager* SceneManager::getInstance()
{
    if (__instance == nullptr) __instance = new SceneManager();
    return __instance;
}

SceneBase* SceneManager::createScene(SceneID id)
{
    switch (id) {
    case MAP_1_BACKGROUND: return new Map_1_Background(MAP_1_BACKGROUND); break;
    case MAP_1_ACTORS : return new Map_1_Actors(MAP_1_ACTORS); break;
    default:
        DebugOut(L"Scene with id %d is defined", id);
    }
}
