# Notes on the game

Each step for adding a feature:
- Define what you want to do e.g Add a hero
- Investigating parts of the engine that you need
-Make notes on the parts and detailed todo list of what to write
Write code
- Add your result to notes (code or scrn shot)
-
## Step 1 - Make my hero show up
Looking in the `main.cpp`
```C++
#include "engine.h"
#include "heros.h"
 engine.create_hero(Heros::nobody);
 ```

 Chracters are defined in `content/actor/heros.h`
 ```const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};```
 "none" is name of sprite in `assets/hero.txt`

 Todo:
 - lok up shareed_ptr in Tour of C++ or c++ reference
- shared-ptr, make-shared: what is the relationship? where do i specify the type?
unordered map? string and reaction
-reaction = std::function<std::unique-ptr<Action>();, what is a function?>