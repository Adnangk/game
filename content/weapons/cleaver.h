#pragma once
#include "actor.h"
#include "engine.h"
#include "weapon.h"
class Cleaver : public Weapon {
   public:
    Cleaver(int damage);
    void use(Engine& engine, Actor& actor, Actor& defender) override;
};