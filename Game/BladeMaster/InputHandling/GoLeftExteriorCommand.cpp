#include "GoLeftExteriorCommand.h"
#include "../HelperHeader/PlayerType.h"
//For testing purpose
#include "../Debug.h"

void GoLeftExteriorCommand::execute(PlayerType * EntityID) {
    DebugOut(L"Go Left Exterior Command\n");
    
    switch (EntityID->currentPlayerType) {
    case PlayerType::JASON:
        EntityID->jason->Test();
        break;
    case PlayerType::SOPHIA:
        EntityID->sophia->Test();
        break;
    }
}