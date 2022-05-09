#pragma once
#include "actor.h"
#include "engine.h"
#include "event.h"
#include "hit.h"

class die : public Event {
   public:
    die(Actor& actor);
    void execute(Engine& engine) override;

   private:
    Actor& actor;
};