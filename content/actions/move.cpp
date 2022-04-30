#include "move.h"

#include "actor.h"
#include "engine.h"
#include "vec.h"
Move::Move(Vec direction) : direction{direction} {};
Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    actor->change_direction(direction);
    Vec new_position = position + direction;

    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_wall() || tile.actor || tile.is_door()) {
        return failure();
    } else {
        actor->move_to(new_position);
        return success();
    }
}