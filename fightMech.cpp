#include "fightMech.h"
#include "characters.h"
#include <iostream>

using namespace std;

void displayFightStats(const Character& character, const Mob& mob) {
    cout << character.type << " Stats: " << "\t";
    cout << mob.name << " Stats: " << endl;

    cout << "HP: " << character.hp << "\t";
    cout << "HP: " << mob.hp << endl;

    cout << "Attack Power: " << character.attackPower << "\t";
    cout << "Attack Power: " << mob.attackPower << endl;

    cout << "Defense: " << character.defense << "\t";
    cout << "Defense: " << mob.defense << endl;

    cout << "Agility: " << character.agility << endl;

    cout << "Magic: " << character.magic << "\t";
    cout << "Magic: " << mob.magic << endl;

    cout << "-----------------------------" << endl;
}

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
        player.purse += mob.purse;
    }
}

void mobAttack(Mob &mob, Character &player) {
    if(mob.magic != 0){
        int random = rand() % 100;
        if(random < 75){
             int damage = calculateDamage(mob.attackPower, player.defense);
            player.hp -= damage;
            cout << mob.name << " attacked you for " << damage << " damage!" << endl;
            if (player.hp <= 0) {
                cout << "You have been defeated!" << endl;
            }
        }
        else{
            int damage = (mob.attackPower * mob.magic / player.agility) - player.defense;
            player.hp -= damage;
            cout << mob.name << " attacked you for " << damage << " damage!" << endl;
            if (player.hp <= 0) {
                cout << "You have been defeated!" << endl;
            }
        }
    }else {
        int damage = calculateDamage(mob.attackPower, player.defense);
        player.hp -= damage;
        cout << mob.name << " attacked you for " << damage << " damage!" << endl;
        if (player.hp <= 0) {
            cout << "You have been defeated!" << endl;
        }
    }
     
   
}

void magicAttack ( Mob &mob, Character &player){
    if(player.magic == 0){
        cout << player.type << " doesnt have any magic" << endl;
    }
    else {
        int random = rand() % 100;
        if(random < 50){
            int damage = (player.attackPower * player.magic) - mob.defense;
            mob.hp -= damage;
            cout << "You attacked " << mob.name << " for " << damage << " damage!" << endl;
            if (mob.hp <= 0) {
            cout << mob.name << " has been defeated!" << endl;
            player.purse += mob.purse;
        }
        }else{
            cout << "Attack Missed!" << endl;
        }
    }
}

void fight(Mob &mob, Character &player) {
    while (mob.hp > 0 && player.hp > 0) {
        cout << "Press 1 to Attack" << endl << "Press 2 to use magic" << endl << "Press 3 to run away " << endl;
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
            displayFightStats(player,mob);
        }
        else if(choice == 2 ) {
            magicAttack(mob,player);

            if (mob.hp > 0) {
                // If mob is still alive, it attacks back
                mobAttack(mob, player);
            }
            displayFightStats(player,mob);
        }
        else if (choice == 3) {
            cout << "You ran away from the fight!" << endl;
            break;
        } 

        else {
            cout << "Invalid choice! Please enter 1, 2 or 3." << endl;
        }

        // Check if the player is dead after the mob's attack
        if (player.hp <= 0) {
            cout << "Game over! You have been defeated by the " << mob.name << "." << endl;
            break;
        }
    }
    
    if (mob.hp <= 0) {
        cout << "You have successfully defeated the " << mob.name << "!" << endl;
        displayStats(player);
    }
}
