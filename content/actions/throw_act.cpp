#include "throw_act.h"

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "hero.h"
#include "hit.h"
#include "iostream"
#include "rest.h"

Result ThrowAct ::perform(Engine& engine) {
    Vec position = actor->get_position();
    // Vec direction = actor->direction;
    //  Vec new_position = position + direction * 2;
    std::vector<Vec> between;
    for (int i; i < 5; ++i) {
        Vec new_position = position + actor->direction;
        between.push_back(new_position);
    }
    for (const Vec& new_position : between) {
        Tile& tile = engine.dungeon.tiles(new_position);
        if (tile.actor) {
            if (actor->team != tile.actor->team) {
                return alternative(Attack{*tile.actor});
            } else {
                return success();
            }
        }
    }
    return alternative(Rest{});
}