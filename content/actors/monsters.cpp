#include "monsters.h"

#include "axe.h"
#include "bhammer.h"
#include "cleaver.h"
#include "engine.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "wander.h"

namespace Monsters {

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    // pursue Hero if monster can see him (If Hero sees me, I see him)
    if (me.is_visible() && engine.hero) {
        Vec from = me.get_position();
        Vec to = engine.hero->get_position();
        std::vector<Vec> path = engine.dungeon.calculate_path(from, to);
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }
    // Monster doesn't see Hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
}
MonsterType goblin() {
    int health = 3;
    return {"goblin", default_speed, health, std::make_shared<BigHammer>(9),
            default_behavior};
}

MonsterType zombie_small() {
    int health = 3;
    return {"zombie_small", default_speed, health,
            std::make_shared<BigHammer>(5), default_behavior};
}

MonsterType muddy() {
    int health = 3;
    return {"muddy", default_speed, health, std::make_shared<Cleaver>(2),
            default_behavior};
}
}  // namespace Monsters