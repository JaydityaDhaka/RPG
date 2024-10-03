#include "characters.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator

    cout << "Welcome to Dragon Quest!" << endl;

    Character player; // Declare the player variable

    while (true) { // Loop for continuous gameplay
        cout << "\nChoose the type of Warrior you want to become: " << endl;
        cout << "1. Swordsman" << endl;
        cout << "2. Spartan" << endl;
        cout << "3. Wizard" << endl;
        cout << "4. Archer" << endl;
        cout << "0. Exit the game" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) { // Exit condition
            cout << "Exiting the game. Goodbye!" << endl;
            break; // Exit the loop and end the program
        }

        player = selectCharacter(choice); // Select character based on user input
        displayStats(player); // Display player stats

        cout << "Good morning player you have woken up in your village!" << endl << "Your goal is to become strong enough and kill the dragon that has been tormenting the lands" << endl << "Kill mobs and trade goods to increase your stats" << endl;

        
    }

    return 0;
}
