#include "InteriorTopDownContext.h"
#include "WeaponSelectCommand.h"
#include "GoLeftInteriorCommand.h"
#include "GoRightInteriorCommand.h"
#include "GoUpInteriorCommand.h"
#include "GoDownInteriorCommand.h"
#include "TossGrenadeCommand.h"
#include "ShootInteriorCommand.h"
#include "Core/InputContext.h"
#include<dinput.h>

InteriorTopDownContext::InteriorTopDownContext() {
    start_button = new WeaponSelectCommand();
    left = new GoLeftInteriorCommand();
    up = new GoUpInteriorCommand();
    right = new GoRightInteriorCommand();
    down = new GoDownInteriorCommand();
    a_button = new TossGrenadeCommand();
    b_button = new ShootInteriorCommand();
}

void InteriorTopDownContext::KeyState(BYTE* keyStates)
{
    InputContext* input = InputContext::GetInstance();
    if (keyStates[DIK_UP] & 0x80) {
        up->currentKeyEventType = Command::Hold;
        up->execute(input->player);
    }
    else if (keyStates[DIK_LEFT] & 0x80) {
        left->currentKeyEventType = Command::Hold;
        left->execute(input->player);
    }
    else if (keyStates[DIK_RIGHT] & 0x80) {
        right->currentKeyEventType = Command::Hold;
        right->execute(input->player);
    }
    else if (keyStates[DIK_DOWN] & 0x80) {
        down->currentKeyEventType = Command::Hold;
        down->execute(input->player);
    }
}

void InteriorTopDownContext::OnKeyDown(int KeyCode)
{
    InputContext* input = InputContext::GetInstance();
    switch (KeyCode)
    {
    case DIK_RETURN:
        start_button->currentKeyEventType = Command::KeyDown;
        start_button->execute(input->player);
        break;
    case DIK_Z:
        a_button->currentKeyEventType = Command::KeyDown;
        a_button->execute(input->player);
        break;
    case DIK_X:
        b_button->currentKeyEventType = Command::KeyDown;
        b_button->execute(input->player);
        break;
    default:
        break;
    }
}

void InteriorTopDownContext::OnKeyUp(int KeyCode)
{
    switch (KeyCode)
    {
    default:
        break;
    }
}
