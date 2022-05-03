#include "opendoor.h"

#include <iomanip>
#include <iostream>

#include "actor.h"
#include "engine.h"
#include "move.h"
#include "updatefov.h"
OpenDoor::OpenDoor(Vec pos) : pos{pos} {};
Result OpenDoor::perform(Engine& engine) {
    Door& door = engine.dungeon.doors.at(pos);
    Tile& tile = engine.dungeon.tiles(pos);
    // if (door.close()) {
    door.open();

    tile.walkable = true;
    //}

    engine.events.add(UpdateFOV{});
    return success();
}