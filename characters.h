#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>

struct Character {
    std::string type;
    int hp;
    int attackPower;
    int defense;
    int agility;
    int magic;
    int purse;
};

void displayStats(const Character& character);
Character selectCharacter(int choice);

#endif // CHARACTERS_H
