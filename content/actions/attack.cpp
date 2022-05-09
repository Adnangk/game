#include "attack.h"

#include "actor.h"
#include "engine.h"
#include "hero.h"
#include "hit.h"
Attack::Attack(Actor& defender) : defender{defender} {}
Result Attack::perform(Engine& engine) {
    actor->attack(defender);
    return success();
}