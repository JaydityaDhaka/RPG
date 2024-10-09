#include "characters.h"
#include "mobs.h"
#include "fightMech.h"
#include "locations.h"
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
            if(location == "Village"){
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
                        fight(opponent, player);
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
                    location = chooseLocation();
                    break;
                
                default:
                    cout << "Enter a valid option" << endl;
                    cout << "What do you want to do in the village?" << endl;
                    cout << "Press 1 to look for mobs" << endl;
                    cout << "press 2 to sleep and replenish Health" << endl;
                    cout << "Press 3 to travel" << endl;
                    
                }
                
            }
            else if( location == "Jungle"){
                    cout << "You are in the Jungle. Wild creatures lurk behind every tree!" << endl;
                    cout << "Press 1 to search for mobs" << endl;
                    cout << "Press 2 to travel back to another location" << endl;

                    int c2;
                    cin >> c2;

                    if (c2 == 1) {
                        Mob opponent = spawnRandomMob(location);
                        displayStatsMob(opponent);
                        cout << "A " << opponent.name << " approaches!" << endl;
                        fight(opponent, player); // Engage in combat
                    } else if (c2 == 2) {
                        location = chooseLocation(); // Travel to another location
                    } else {
                        cout << "Invalid option." << endl;
                    }
            }
            else if( location == "Town"){
                cout << "You are now in the Town. It's a peaceful place to rest and trade." << endl;
                cout << "Press 1 to look for mobs" << endl;
                cout << "Press 2 to travel to another location" << endl;

                int c2;
                cin >> c2;

                if (c2 == 1) {
                    Mob opponent = spawnRandomMob(location);
                    displayStatsMob(opponent);
                    cout << "A " << opponent.name << " appears!" << endl;
                    fight(opponent, player);
                } else if (c2 == 2) {
                    location = chooseLocation(); // Travel to another location
                } else {
                    cout << "Invalid option." << endl;
                }

            }
            else if( location == "Castle"){
                 cout << "You are at the Castle. It stands tall and mysterious." << endl;
                cout << "Press 1 to search for mobs" << endl;
                cout << "Press 2 to travel to another location" << endl;

                int c2;
                cin >> c2;

                if (c2 == 1) {
                    Mob opponent = spawnRandomMob(location);
                    displayStatsMob(opponent);
                    cout << "A " << opponent.name << " challenges you!" << endl;
                    fight(opponent, player);
                } else if (c2 == 2) {
                    location = chooseLocation(); // Travel to another location
                } else {
                    cout << "Invalid option." << endl;
                }
            }
            else if( location == "Dragon's Lair"){
                cout << "Dragon" << endl;
            }  
        }
        
    }

    return 0;
}
