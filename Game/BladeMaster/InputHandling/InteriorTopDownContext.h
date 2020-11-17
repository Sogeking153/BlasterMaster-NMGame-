#pragma once
#include "Core/Context.h"

class Command;
class InteriorTopDownContext : public Context {
public:
    InteriorTopDownContext();
    bool Handle(MappedInput &);

    // Inherited via Context
    virtual void KeyState(BYTE* keyStates) override;
    virtual void OnKeyDown(int KeyCode) override;
    virtual void OnKeyUp(int KeyCode) override;
private:
    Command * up;
    Command * left;
    Command * right;
    Command * down;
    Command * a_button;
    Command * b_button;
    Command * start_button;

    
};