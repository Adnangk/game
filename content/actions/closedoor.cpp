#include "closedoor.h"

#include <iomanip>
#include <iostream>

#include "engine.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine) {
    bool closed_any_door{false};

    auto /*std::vector<Vec>*/ neighbors =
        engine.dungeon.neighbors(actor->get_position());

    for (const Vec& position : neighbors) {
        Tile& tile = engine.dungeon.tiles(position);
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(position);
            if (door.is_open() && !tile.actor) {
                door.close();
                tile.walkable = false;
                closed_any_door = true;
            }
        }
    }

    if (closed_any_door) {
        engine.events.add(UpdateFOV{});
        return success();
    } else {
        return failure();
    }
}