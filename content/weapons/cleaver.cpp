#include "cleaver.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"
#include "throw.h"

Cleaver::Cleaver(int damage) : Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Actor& attacker, Actor& defender) {
    // engine.events.add(Hit{defender, damage});
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Throw{sprite, direction, defender, damage});
}