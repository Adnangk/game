#pragma once
#include "action.h"
#include "vec.h"

class OpenDoor : public Action {
   public:
    OpenDoor(Vec pos);
    Result perform(Engine& engine) override;

   private:
    Vec pos;
};