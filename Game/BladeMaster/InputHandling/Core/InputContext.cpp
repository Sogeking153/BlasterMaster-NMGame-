#include "InputContext.h"
#include "MappedInput.h"
#include "Context.h"
#include "../ExteriorSideScrollingContext.h"
#include "../InteriorTopDownContext.h"
#include "DirectInput.h"
#include "../../Core/Coordinator.h"
#include "../../HelperHeader/PlayerType.h"

InputContext * InputContext::__instance = NULL;
InputContext::InputContext() {}

void InputContext::Dispatch()
{
    lowLevelHandler->ProcessKeyboard();
}
void InputContext::Init(HWND hWnd)
{
    mListContexts.emplace(ContextType::Interior,std::make_unique<InteriorTopDownContext>());
    mListContexts.emplace(ContextType::Exterior,std::make_unique<ExteriorSideScrollingContext>());
    currentContext = ContextType::Interior;
    lowLevelHandler = new DirectInput();
    lowLevelHandler->InitKeyboard(hWnd);

    player = new PlayerType();
}
void InputContext::HandleKeyState(BYTE * keyState)
{
    mListContexts[currentContext]->KeyState(keyState);
}
void InputContext::OnKeyDown(int keyCode)
{
    mListContexts[currentContext]->OnKeyDown(keyCode);
}
void InputContext::OnKeyUp(int keyCode)
{
    mListContexts[currentContext]->OnKeyUp(keyCode);
}
void InputContext::SwitchContext(ContextType newContext)
{
    currentContext = newContext;
}
InputContext* InputContext::GetInstance() {
    if (__instance == nullptr) __instance = new InputContext();
    return __instance;
}
