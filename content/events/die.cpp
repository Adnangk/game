#include "die.h"
die::die(Actor& actor) : actor{actor} {}
void die::execute(Engine& engine) {
    // remove actor from its tile
    engine.dungeon.remove_actor(actor.get_position());
    // remove it from live actors
    actor.health = 0;
    actor.alive = false;
}