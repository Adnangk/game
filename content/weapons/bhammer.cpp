#include "bhammer.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

BigHammer::BigHammer(int damage) : Weapon{"hammer_big", damage} {}

void BigHammer::use(Engine& engine, Actor& attacker, Actor& defender) {
    // engine.events.add(Hit{defender, damage});
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}