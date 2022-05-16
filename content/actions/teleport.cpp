#include "teleport.h"

#include <iostream>

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "opendoor.h"
#include "vec.h"

Result Teleport ::perform(Engine& engine) {
    Vec position = actor->get_position();
    Vec direction = actor->direction;

    Vec new_position = position + direction;
    Tile tile = engine.dungeon.tiles(new_position);

    while (tile.is_wall() == false && !tile.actor) {
        new_position = new_position + direction;
        tile = engine.dungeon.tiles(new_position);
    }

    new_position = new_position - direction;
    actor->move_to(new_position);
    if (tile.actor) {
        return alternative(Attack(*tile.actor));
    }

    return success();
}