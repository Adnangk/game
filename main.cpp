#include "engine.h"
#include "heros.h"
#include "monsters.h"
#include "vec.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::wizard);
    engine.create_monster(Monsters::goblin());
    engine.create_monster(Monsters::zombie_small());
    engine.create_monster(Monsters::muddy());
    engine.create_monster(Monsters::muddy());
    engine.create_monster(Monsters::muddy());
    engine.create_monster(Monsters::muddy());

    engine.run();
}
