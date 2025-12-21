// ABOUTME: Defines the progression condition provider interface for item gating.
// ABOUTME: Allows item progression checks to use external condition sources.

#pragma once

#include "Common.h"

class Player;

class ProgressionConditionProvider
{
public:
    virtual ~ProgressionConditionProvider() = default;
    virtual bool IsItemAllowed(Player* player, uint32 itemId) const = 0;
};
