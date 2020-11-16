#pragma once
#include "Core/Command.h"
class AimUpCommand : public Command {
    void execute(PlayerType * player);
};