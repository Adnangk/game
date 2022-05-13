#include "throw_act.h"

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "hero.h"
#include "hit.h"
#include "rest.h"

Result ThrowAct ::perform(Engine& engine) {
    Vec position = actor->get_position();

    Vec new_position = position + actor->direction * 2;

    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.actor) {
        if (actor->team != tile.actor->team) {
            return alternative(Attack{*tile.actor});
        } else {
            return success();
        }
    }
    return alternative(Rest{});
}