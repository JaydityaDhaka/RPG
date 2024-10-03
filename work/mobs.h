#ifndef MOBS_H
#define MOBS_H

#include <string>

struct Mob {
    std::string name;
    int hp;
    int attackPower;
    int defense;
};

Mob createMob(std::string mobName);
Mob spawnRandomMob(std::string location);

#endif // MOBS_H
