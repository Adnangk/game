#include "throw.h"

#include <cmath>

#include "engine.h"
#include "hit.h"

constexpr int duration = 10;
Throw::Throw(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{duration},

      sprite{sprite},
      direction{direction.x, -direction.y},

      defender{defender},
      damage{damage},
      copy{sprite},
      starting_angle{sprite.angle},
      delta{3} {
    // direction.y *= -1;
}
// modify the sprite
void Throw::execute(Engine& engine) {
    // sprite.angle = starting_angle + delta * frame_count;
    // void throw_w(Engine & engine, Sprite & sprite, Vec direction, double
    // delta);

    sprite.shift = sprite.shift + direction * delta;
}

void Throw::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}
