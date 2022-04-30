#pragma once

#include "herotype.h"
#include "move.h"
#include "none.h"
#include "rest.h"

namespace Heros {

constexpr int default_speed{8};
const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};

std::unordered_map<std::string, Reaction> key_bindings = {
    {"Right",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"Left",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"Up",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"Down",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"B", []() { return std::make_unique<Rest>(); }},
};

const HeroType wizard{"wizard", default_speed, 15, std::make_shared<None>(),
                      key_bindings};

}  // namespace Heros
