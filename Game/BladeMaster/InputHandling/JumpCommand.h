#pragma once
#include "Core/Command.h"
class JumpCommand : public Command {
    void execute(PlayerType * player);
};