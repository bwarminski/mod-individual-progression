// ABOUTME: Declares item progression rules accessible to other modules.
// ABOUTME: Exposes item allowance checks without pulling in full progression headers.

#pragma once

#include "Common.h"

class Player;

bool IsItemAllowedForProgression(Player* player, uint32 itemId);
