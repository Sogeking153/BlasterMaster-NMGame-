#pragma once
#include "EventBase.h"
/*
  Concrete derivatives store member function pointers for different specific
  event types and are also responsible for proper down-casting to actual event types when calling the handling method
*/
class HandlerFunctionBase {
public:
  virtual ~HandlerFunctionBase() {};
  void exec(const Event * e) {call(e);}
private:
  virtual void call(const Event *) = 0;
};
// MemberFunctionHandler's purpose is to safely cast to proper event type.
template<typename T, typename EventT>
class MemberFunctionHandler : public HandlerFunctionBase{
public:
  typedef void (T::*memFunction)(const EventT *); //Forwar declaration
  MemberFunctionHandler(T* obj, memFunction _memfunction): _instance(obj), _function (_memfunction){}
  void call(const Event * event) {
    (_instance->*_function)(static_cast<const EventT *>(event));
  }
private:
  T* _instance;
  memFunction _function;
};
