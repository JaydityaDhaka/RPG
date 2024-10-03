#include "characters.h"
#include <iostream>

using namespace std;

void displayStats(const Character& character) {
    cout << character.type << " Stats: " << endl;
    cout << "HP: " << character.hp << endl;
    cout << "Attack Power: " << character.attackPower << endl;
    cout << "Defense: " << character.defense << endl;
    cout << "Agility: " << character.agility << endl;
    cout << "Magic: " << character.magic << endl;
    cout << "Coins: " << character.purse << " coins" << endl;
    cout << "-----------------------------" << endl;
}

Character selectCharacter(int choice) {
    Character swordsman = {"Swordsman", 120, 15, 10, 7, 0, 100};
    Character spartan = {"Spartan", 150, 20, 15, 5, 0, 100};
    Character wizard = {"Wizard", 100, 10, 5, 7, 20, 100};
    Character archer = {"Archer", 110, 12, 8, 12, 5, 100};

    switch (choice) {
        case 1:
            return swordsman;
        case 2:
            return spartan;
        case 3:
            return wizard;
        case 4:
            return archer;
        default:
            cout << "Invalid choice! Please select a valid warrior type." << endl;
            return {"None", 0, 0, 0, 0, 0};
    }
}
