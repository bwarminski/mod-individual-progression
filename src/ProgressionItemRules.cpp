// ABOUTME: Implements shared item progression rules for other modules.
// ABOUTME: Delegates item allowance checks to the individual progression system.

#include "ProgressionItemRules.h"

#include "IndividualProgression.h"

bool IsItemAllowedForProgression(Player* player, uint32 itemId)
{
    if (!sIndividualProgression->enabled)
    {
        return true;
    }

    return sIndividualProgression->IsItemAllowedForProgression(player, itemId);
}
