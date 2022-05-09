#pragma once
#include "actor.h"
#include "engine.h"
#include "weapon.h"
class BigHammer : public Weapon {
   public:
    BigHammer(int damage);
    void use(Engine& engine, Actor& actor, Actor& defender) override;
};