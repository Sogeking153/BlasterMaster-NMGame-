#include "ExteriorSideScrollingContext.h"
#include "JumpCommand.h"
#include "WeaponSelectCommand.h"
#include "SwitchModeCommand.h"
#include "ShootExteriorCommand.h"
#include "GoLeftExteriorCommand.h"
#include "GoRightExteriorCommand.h"
#include "AimUpCommand.h"
#include "LayDownCommand.h"
#include "Core/InputContext.h"
#include "../HelperHeader/PlayerType.h"
#include <dinput.h>

ExteriorSideScrollingContext::ExteriorSideScrollingContext() {
  up = new AimUpCommand();
  start_button = new WeaponSelectCommand();
  select_button = new SwitchModeCommand();
  b_button = new ShootExteriorCommand();
  left = new GoLeftExteriorCommand();
  right = new GoRightExteriorCommand();
  a_button = new JumpCommand();
  down = new LayDownCommand();
}

void ExteriorSideScrollingContext::KeyState(BYTE* keyStates)
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
    else if (keyStates[DIK_Z] & 0x80) {
        a_button->currentKeyEventType = Command::Hold;
        a_button->execute(input->player);
    }
}

void ExteriorSideScrollingContext::OnKeyDown(int KeyCode)
{
    InputContext* input = InputContext::GetInstance();
    switch (KeyCode)
    {
    case DIK_DOWN:
        down->currentKeyEventType = Command::KeyDown;
        down->execute(input->player);
        break;
    case DIK_LSHIFT:
        select_button->currentKeyEventType = Command::KeyDown;
        select_button->execute(input->player);
        break;
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

void ExteriorSideScrollingContext::OnKeyUp(int KeyCode)
{
    InputContext* input = InputContext::GetInstance();
    switch (KeyCode)
    {
    case DIK_UP:
        up->currentKeyEventType = Command::KeyUp;
        up->execute(input->player);
        break;
    case DIK_LEFT:
        left->currentKeyEventType = Command::KeyUp;
        left->execute(input->player);
        break;
    case DIK_RIGHT:
        right->currentKeyEventType = Command::KeyUp;
        right->execute(input->player);
        break;
    case DIK_Z:
        a_button->currentKeyEventType = Command::KeyUp;
        a_button->execute(input->player);
        break;

    default:
        break;
    }

}
