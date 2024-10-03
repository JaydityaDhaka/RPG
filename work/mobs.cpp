#include "mobs.h"
#include <cstdlib> // For rand()
#include <iostream>

using namespace std;

Mob spawnRandomMob(string location) {
    int spawnChance = rand() % 100 + 1; 
    int randomNumber = rand() % 100 + 1; // For mob selection if a mob spawns
    string mobName;

    // Determine if a mob spawns based on location-specific probabilities
    if (location == "Castle") {
        if (spawnChance > 80) {
            cout << "No mobs spawn here in the Castle this time." << endl;
            return {"None", 0, 0, 0};
        }
        // 80% chance of mobs spawning
        if (randomNumber <= 60) mobName = "Skeleton";  // Skeletons are most common
        else if (randomNumber <= 70) mobName = "Thug";
        else if (randomNumber <= 80) mobName = "Wolf";
        else mobName = "Witch";
    } 
    else if (location == "Town") {
        if (spawnChance > 30) {
            cout << "No mobs spawn here in the Town this time." << endl;
            return {"None", 0, 0, 0};
        }
        // 30% chance of mobs spawning
        if (randomNumber <= 70) mobName = "Thug";
        else if (randomNumber <= 80) mobName = "Skeleton";
        else if (randomNumber <= 90) mobName = "Wolf";
        else mobName = "Witch";
    } 
    else if (location == "Village") {
        if (spawnChance > 40) {
            cout << "No mobs spawn here in the Village this time." << endl;
            return {"None", 0, 0, 0};
        }
        // 40% chance of mobs spawning
        if (randomNumber <= 40) mobName = "Wolf";
        else if (randomNumber <= 80) mobName = "Thug";
        else if (randomNumber <= 90) mobName = "Skeleton";
        else mobName = "Witch";
    } 
    else if (location == "Jungle") {
        if (spawnChance > 70) {
            cout << "No mobs spawn here in the Jungle this time." << endl;
            return {"None", 0, 0, 0};
        }
        // 70% chance of mobs spawning
        if (randomNumber <= 50) mobName = "Wolf";
        else if (randomNumber <= 80) mobName = "Witch";
        else if (randomNumber <= 90) mobName = "Skeleton";
        else mobName = "Thug";
    } 
    else if (location == "Dragon's Lair") {
        cout << "No mobs spawn in the Dragon's Lair, only a fearsome Dragon awaits!" << endl;
        return {"None", 0, 0, 0};
    }

    // Return the mob created from the random selection
    return createMob(mobName);
}
