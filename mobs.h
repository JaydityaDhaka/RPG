#ifndef MOBS_H
#define MOBS_H

#include <string>

struct Mob {
    std::string name;
    int hp;
    int attackPower;
    int defense;
    int magic;
    int purse;
};

void displayStatsMob(const Mob& character);
Mob spawnRandomMob(std::string location);
Mob spawnMinotaur(std::string location);
Mob spawnCentaur(std::string location);
Mob spawnDragon(std::string location);

#endif // MOBS_H
