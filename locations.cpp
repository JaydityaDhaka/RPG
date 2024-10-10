#include "ASCII.h"
#include "locations.h"
#include "mobs.h"
#include <iostream>

using namespace std;

string chooseLocation() {
    cout << "\nNow choose a location to explore: " << endl;
    cout << "1. Town" << endl;
    cout << "2. Jungle" << endl;
    cout << "3. Castle" << endl;
    cout << "4. Village" << endl;
    cout << "5. Dragon's Lair" << endl;
    
    int locationChoice;
    cin >> locationChoice;
    // while(true){
        string location;
        switch (locationChoice) {
            case 1:
                location = "Town";
                displayTown();
                // cout << "You are now in the Town. It's a peaceful place to rest and trade." << endl;
                break;
            case 2:
                location = "Jungle";
                // cout << "You enter the Jungle. Wild creatures lurk behind every tree!" << endl;
                break;
            case 3:
                location = "Castle";
                displaycastle();
                // cout << "You approach the Castle. It stands tall and mysterious." << endl;
                break;
            case 4:
                location = "Village";
                // cout << "You arrive at the Village. Farmers and traders live here." << endl;
                break;
            case 5:
                location = "Dragon's Lair";
                displayDragon1();
                // cout << "You dare to enter the Dragon's Lair. The smell of fire and smoke fills the air!" << endl;
                break;
            default:
                cout << "Invalid location choice! Please select a valid option." << endl;
                break;;
        }

    // }
    return location;
    

}
