#pragma once
#include "Core/Context.h"

class Command;
class ExteriorSideScrollingContext : public Context {
public:
  ExteriorSideScrollingContext();
  //bool Handle(MappedInput &);

  // Inherited via Context
  virtual void KeyState(BYTE* state) override;
  virtual void OnKeyDown(int KeyCode) override;
  virtual void OnKeyUp(int KeyCode) override;
private:
  Command * up;
  Command * down;
  Command * left;
  Command * right;
  Command * a_button;
  Command * b_button;
  Command * start_button;
  Command * select_button;

  
};
