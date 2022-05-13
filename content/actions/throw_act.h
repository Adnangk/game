#pragma once
#include "action.h"
#include "actor.h"
#include "engine.h"
#include "throw.h"

class ThrowAct : public Action {
   public:
    // ThrowAct(Vec direction);
    Result perform(Engine& engine) override;

   private:
    // Actor& defender;
    // double delta;
    // Vec direction;
};