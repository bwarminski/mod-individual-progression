// ABOUTME: Defines the progression condition provider interface for item gating.
// ABOUTME: Allows item progression checks to use external condition sources.

#pragma once

#include "ConditionMgr.h"
#include "Common.h"

#include <functional>
#include <mutex>
#include <unordered_map>
#include <vector>

class Player;

class ProgressionConditionProvider
{
public:
    virtual ~ProgressionConditionProvider() = default;
    virtual bool IsItemAllowed(Player* player, uint32 itemId) const = 0;
};

class ProgressionConditionStore
{
public:
    using ConditionLoader = std::function<std::vector<Condition>()>;

    explicit ProgressionConditionStore(ConditionLoader loader);

    ConditionList const& GetConditionsForItem(uint32 itemId) const;

private:
    struct ItemConditions
    {
        std::vector<Condition> storage;
        ConditionList conditions;
    };

    void LoadAllConditions() const;

    ConditionLoader loader;
    mutable std::once_flag loadOnce;
    mutable std::unordered_map<uint32, ItemConditions> itemConditions;
    mutable ConditionList emptyConditions;
};
