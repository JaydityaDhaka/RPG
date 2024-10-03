#include "encounters.h"
#include <cstdlib> // For rand()
#include <iostream>

using namespace std;

void encounterMob(Player &player, Mob &mob) {
    if (mob.name == "None") {
        cout << "There are no enemies here. You can proceed." << endl;
        return;
    }

    cout << "You have encountered a " << mob.name << "!" << endl;

    // Give the player the option to fight or run
    string choice;
    cout << "Do you want to (1) Fight or (2) Run? ";
    cin >> choice;

    if (choice == "1") {
        // Handle the fight logic here
        cout << "You chose to fight the " << mob.name << "!" << endl;
        // Combat logic (same as discussed earlier)
        while (player.hp > 0 && mob.hp > 0) {
            mob.hp -= player.attackPower;
            cout << "You hit the " << mob.name << " for " << player.attackPower << " damage!" << endl;

            if (mob.hp <= 0) {
                cout << "You defeated the " << mob.name << "!" << endl;
                return;
            }

            player.hp -= mob.attackPower;
            cout << "The " << mob.name << " hits you for " << mob.attackPower << " damage!" << endl;

            if (player.hp <= 0) {
                cout << "You have been defeated!" << endl;
                return;
            }
        }
    } else if (choice == "2") {
        int runChance = rand() % 100 + 1;
        if (runChance <= 50) {
            cout << "You successfully ran away!" << endl;
        } else {
            cout << "You failed to escape! The " << mob.name << " attacks you!" << endl;
            player.hp -= mob.attackPower;
            cout << "The " << mob.name << " hits you for " << mob.attackPower << " damage!" << endl;
        }
    } else {
        cout << "Invalid choice. The " << mob.name << " attacks you!" << endl;
        player.hp -= mob.attackPower;
    }
}
