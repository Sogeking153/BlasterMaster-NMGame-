#pragma once
#include "Core/Command.h"
class GoRightExteriorCommand : public Command {
    void execute(PlayerType * player);
};