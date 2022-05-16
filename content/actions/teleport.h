#pragma once
#include "action.h"
#include "dungeon.h"
#include "engine.h"
#include "vec.h"

class Teleport : public Action {
   public:
    Result perform(Engine& engine) override;
};