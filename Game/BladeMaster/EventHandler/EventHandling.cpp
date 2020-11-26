#include "EventHandling.h"
#include "EventBase.h"

EventHandling* EventHandling::__instance = NULL;
/*
  After receiving a generic event of type Event it determines its actual type and then calls the
  proper handler method with valid event as a parameter.
*/
void EventHandling::handleEvent(const Event * event) {
  std::map<std::type_index , HandlerFunctionBase *>::iterator actualEventType = mHandlers.find(std::type_index(typeid(event)));
  if(actualEventType != mHandlers.end()) {
    actualEventType->second->exec(event);
  }
}

EventHandling* EventHandling::GetInstance()
{
    if (__instance == nullptr) __instance = new EventHandling();
    return __instance;
}
