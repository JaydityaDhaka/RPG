#ifndef FIGHTMECH_H
#define FIGHTMECH_H

#include "mobs.h"
#include "characters.h"

void displayFightStats(const Character& character, const Mob& mob);

void fight(Mob &mob, Character &player);
int calculateDamage(int attackPower, int defense);

void playerAttack(Mob &mob, Character &player);
void mobAttack(Mob &mob, Character &player);

#endif // FIGHTMECH_H
