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

bool InteriorTopDownContext::Handle(MappedInput & mappedInput) {
    if(!isActive) return false;
    InputContext* input = InputContext::GetInstance();
    int actorID = input->GetPlayerID();
    if (mappedInput.KeyCode != -1 && (mappedInput.KeyData & 0x80) > 0) {
        if (mappedInput.KeyCode == DIK_RETURN) {
            start_button->execute(actorID);
        } else if (mappedInput.KeyCode ==DIK_Z) {
            a_button->execute(actorID);
        }
        else if (mappedInput.KeyCode == DIK_X) {
            b_button->execute(actorID);
        }
    }
    

    if(mappedInput.keyStates[DIK_UP] & 0x80) {
        up->execute(actorID);
    } else if(mappedInput.keyStates[DIK_LEFT] & 0x80) {
        left->execute(actorID);
    } else if(mappedInput.keyStates[DIK_RIGHT] & 0x80) {
        right->execute(actorID);
    } else if (mappedInput.keyStates[DIK_DOWN] & 0x80) {
        down->execute(actorID);
    }

    return true;
}
