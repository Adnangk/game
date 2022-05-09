// Adnan Ahmed
#include "move.h"

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "opendoor.h"
#include "vec.h"
Move::Move(Vec direction) : direction{direction} {};
Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    actor->change_direction(direction);
    Vec new_position = position + direction;

    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_wall()) {
        return failure();  // alternative (Attack{*tile.actor})
        // Attack& actor
    } else if (tile.actor) {
        if (actor->team != tile.actor->team) {
            return alternative(Attack{*tile.actor});

        } else {
            return success();
        }
    }

    else if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(new_position);
        if (door.is_open() == false) {
            return alternative(OpenDoor{new_position});
        }
    }
    actor->move_to(new_position);
    return success();
}