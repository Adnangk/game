#include "swing.h"

#include <cmath>

#include "engine.h"
#include "hit.h"

constexpr int duration = 10;
Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{duration},
      sprite{sprite},
      copy{sprite},
      defender{defender},
      damage{damage},
      starting_angle{sprite.angle} {
    if (direction == Vec{1, 0}) {
        starting_angle = 0;
        delta = 360.0 / (duration - 1);
    } else if (direction == Vec{-1, 0}) {
        starting_angle = 0;
        delta = -360.0 / (duration / 1);
    } else if (direction == Vec{0, 1}) {
        // sprite.shift.y -= 12;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 0;  //-75 * sign;
        delta = 360.0 / (duration - 1) * sign;
    } else {
        // sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 0;  // 135 * sign;
        delta = 360.0 / (duration - 1) * sign;
    }
}
// modify the sprite
void Swing::execute(Engine& engine) {
    sprite.angle = starting_angle + delta * frame_count;
    // sprite.shift.x += 3;
}

void Swing::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}
