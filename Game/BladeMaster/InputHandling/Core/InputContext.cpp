#include "InputContext.h"
#include "MappedInput.h"
#include "Context.h"
#include "../ExteriorSideScrollingContext.h"
#include "../InteriorTopDownContext.h"
#include "DirectInput.h"
#include "../../HelperHeader/PlayerType.h"

InputContext * InputContext::__instance = NULL;
InputContext::InputContext() {}

void InputContext::Dispatch()
{
    MappedInput mappedInput = lowLevelHandler->ProcessKeyboard();
    for(std::list<std::unique_ptr<Context>>::iterator it = mListContexts.begin(); it != mListContexts.end() ; it++) {
      if(it->get()->Handle(mappedInput) == true) {
        return;
      }
    }

}
void InputContext::Init(HWND hWnd)
{
    mListContexts.push_front(std::make_unique<InteriorTopDownContext>());
    mListContexts.push_front(std::make_unique<ExteriorSideScrollingContext>());
    mListContexts.front()->isActive = true;
    lowLevelHandler = new DirectInput();
    lowLevelHandler->InitKeyboard(hWnd);

    player = new PlayerType();
}
InputContext* InputContext::GetInstance() {
    if (__instance == nullptr) __instance = new InputContext();
    return __instance;
}