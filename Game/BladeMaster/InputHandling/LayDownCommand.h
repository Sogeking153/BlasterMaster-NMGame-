#pragma once
#include "Core/Command.h"
class LayDownCommand : public Command {
    void execute(PlayerType * player);
};