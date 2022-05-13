#pragma once
#include "actor.h"
#include "event.h"
class Throw : public Event {
   public:
    Throw(Sprite& sprite, Vec direction, Actor& defender, int damage);
    // void throw_w(Engine& engine, Sprite& sprite, Vec direction, double
    // delta);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

   private:
    Sprite& sprite;
    Vec direction;

    Actor& defender;
    int damage;
    Sprite copy;

    double starting_angle, delta;
};