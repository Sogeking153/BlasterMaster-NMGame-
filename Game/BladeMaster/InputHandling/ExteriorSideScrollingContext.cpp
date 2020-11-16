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

bool ExteriorSideScrollingContext::Handle(MappedInput & mappedInput) {
  if(!isActive) return false;
  InputContext* input = InputContext::GetInstance();
  int actorID = input->playerID;
  if (mappedInput.KeyCode != -1 && (mappedInput.KeyData & 0x80) > 0) {
      if (mappedInput.KeyCode == DIK_DOWN) {
          down->execute(input->player);
      }
      else if (mappedInput.KeyCode == DIK_LSHIFT) {
          select_button->execute(input->player);
      }
      else if (mappedInput.KeyCode == DIK_RETURN) {
          start_button->execute(input->player);
      }
      else if (mappedInput.KeyCode == DIK_UP) {
          up->execute(input->player);
      }
      else if (mappedInput.KeyCode == DIK_Z) {
          a_button->execute(input->player);
      }
      else if (mappedInput.KeyCode == DIK_X) {
          b_button->execute(input->player);
      }
  }

  if(mappedInput.keyStates[DIK_UP] & 0x80) {
    up->execute(input->player);
    up->isHold = true;
  } else if(mappedInput.keyStates[DIK_LEFT] & 0x80) {
    left->execute(input->player);
  } else if(mappedInput.keyStates[DIK_RIGHT] & 0x80) {
    right->execute(input->player);
  } else if(mappedInput.keyStates[DIK_Z] & 0x80) {
    a_button->execute(input->player);
    a_button->isHold = true;
  }

  return true;
}
