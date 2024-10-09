#include "characters.h"
#include "mobs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator

    cout << "Welcome to Dragon Quest!" << endl;

    Character player;

    while (true) { 
        cout << "\nChoose the type of Warrior you want to become: " << endl;
        cout << "1. Swordsman" << endl;
        cout << "2. Spartan" << endl;
        cout << "3. Wizard" << endl;
        cout << "4. Archer" << endl;
        cout << "0. Exit the game" << endl;

        int c1;             //choice 1
        cin >> c1;

        if (c1 == 0) { 
            cout << "Exiting the game. Goodbye!" << endl;
            break; 
        }

        player = selectCharacter(c1); // Select character based on user input
        displayStats(player); // Display player stats

        cout << "Good morning player you have woken up in your village!" << endl << "Your goal is to become strong enough and kill the dragon that has been tormenting the lands" << endl << "Kill mobs and trade goods to increase your stats" << endl;

        string location;
        location = "Village";

        
        while(true){
            cout << "What do you want to do in the village?" << endl;
            cout << "Press 1 to look for mobs" << endl;
            cout << "press 2 to sleep and replenish Health" << endl;
            cout << "Press 3 to travel" << endl;
            int c2;
            cin >> c2;          //choice 2
            Mob opponent;

            switch (c2)
            {
            case 1:
                cout << "a mob appeared" << endl;
                opponent = spawnRandomMob(location);
                displayStatsMob(opponent);
                cout << "A " << opponent.name << " stands in front of you " << endl << "Do you want to fight or run away" << endl;  
                int c3;              //choice
                cout << "Press 1 to fight" << endl << "Press 2 to run away" << endl; 
                cin >> c3;

                switch (c3)
                {
                case 1:
                    // fight mechanics
                    break;

                case 2:

                    break;
                
                default:
                    cout << "Invlaid Input" << endl;
                    cout << "Press 1 to fight" << endl << "Press 2 to run away" << endl; 
                    break;
                }
                
                break;
            
            case 2:
                cout << "you heatlh has replenished" << endl;

                displayStats(player);
                break;

            case 3:
                cout << "Where do you want to travel" << endl;
                break;
            
            default:
                cout << "Enter a valid option" << endl;
                cout << "What do you want to do in the village?" << endl;
                cout << "Press 1 to look for mobs" << endl;
                cout << "press 2 to sleep and replenish Health" << endl;
                cout << "Press 3 to travel" << endl;
                
            }
        }
        

        
    }

    return 0;
}
