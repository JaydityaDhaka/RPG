#include "fightMech.h"
#include <iostream>

using namespace std;

int calculateDamage(int attackPower, int defense) {
    int damage = attackPower - defense;
    return (damage > 0) ? damage : 1;  // Ensure minimum damage is 1
}

void playerAttack(Mob &mob, Character &player) {
    int damage = calculateDamage(player.attackPower, mob.defense);
    mob.hp -= damage;
    cout << "You attacked " << mob.name << " for " << damage << " damage!" << endl;
    if (mob.hp <= 0) {
        cout << mob.name << " has been defeated!" << endl;
    }
}

void mobAttack(Mob &mob, Character &player) {
    int damage = calculateDamage(mob.attackPower, player.defense);
    player.hp -= damage;
    cout << mob.name << " attacked you for " << damage << " damage!" << endl;
    if (player.hp <= 0) {
        cout << "You have been defeated!" << endl;
    }
}

void fight(Mob &mob, Character &player) {
    while (mob.hp > 0 && player.hp > 0) {
        cout << "Press 1 to Attack" << endl << " 2 to Run away: " << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            // Player attacks first
            playerAttack(mob, player);
            
            // Check if mob is dead
            if (mob.hp > 0) {
                // If mob is still alive, it attacks back
                mobAttack(mob, player);
            }
        } 
        else if (choice == 2) {
            cout << "You ran away from the fight!" << endl;
            break;
        } 
        else {
            cout << "Invalid choice! Please enter 1 or 2." << endl;
        }

        // Check if the player is dead after the mob's attack
        if (player.hp <= 0) {
            cout << "Game over! You have been defeated by the " << mob.name << "." << endl;
            break;
        }
    }
    
    if (mob.hp <= 0) {
        cout << "You have successfully defeated the " << mob.name << "!" << endl;
    }
}
