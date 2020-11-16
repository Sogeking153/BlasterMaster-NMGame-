#pragma once
#include "Core/Command.h"
class GoLeftInteriorCommand : public Command {
    void execute(PlayerType * player);
};
