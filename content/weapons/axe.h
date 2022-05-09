#pragma once
#include "actor.h"
#include "engine.h"
#include "weapon.h"
class Axe : public Weapon {
   public:
    Axe(int damage);
    void use(Engine& engine, Actor& actor, Actor& defender) override;
};