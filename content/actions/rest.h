#pragma once
#include "action.h"
#include "dungeon.h"
#include "vec.h"

// Do nothing this turn
class Rest : public Action {
   public:
    Result perform(Engine& engine) override;
};
