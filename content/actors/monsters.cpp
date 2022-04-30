#include "monsters.h"

#include "monster.h"
#include "none.h"
#include "rest.h"

namespace Monsters {

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    return std::make_unique<Rest>();
}

MonsterType goblin() {
    int health = 3;
    return {"goblin", default_speed, health, std::make_shared<None>(),
            default_behavior};
}
}  // namespace Monsters