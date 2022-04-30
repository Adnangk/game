#pragma once
#include <memory>

#include "action.h"
#include "monster.h"

namespace Monsters {
constexpr int default_speed{8};
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);

MonsterType goblin();

}  // namespace Monsters
