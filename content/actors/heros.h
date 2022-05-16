// Adnan Ahmed
#pragma once
#include "bhammer.h"
#include "cleaver.h"
#include "closedoor.h"
#include "herotype.h"
#include "move.h"
#include "none.h"
#include "opendoor.h"
#include "rest.h"
#include "teleport.h"
#include "throw_act.h"
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

    {"C", []() { return std::make_unique<CloseDoor>(); }},
    {"B", []() { return std::make_unique<ThrowAct>(); }},
    {"J", []() { return std::make_unique<Teleport>(); }},
};

const HeroType wizard{"wizard", default_speed, 15,
                      std::make_shared<BigHammer>(12), key_bindings};

}  // namespace Heros
