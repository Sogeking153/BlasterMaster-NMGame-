#include "GoRightExteriorCommand.h"
#include "../Core/Coordinator.h"
#include "../InputHandling/Core/InputContext.h"
#include "../Component/PositionComponent.h"
//For testing purpose
#include "../Debug.h"

void GoRightExteriorCommand::execute(PlayerType * player) {
    DebugOut(L"Go Right Exterior Command\n");
    InputContext* context = InputContext::GetInstance();

}