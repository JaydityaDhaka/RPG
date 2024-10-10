#include "characters.h"
#include "mobs.h"
#include "fightMech.h"
#include "locations.h"
#include "shop.h"
#include "ASCII.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    while(true){
        srand(time(0)); // Seed the random number generator

        cout << "Welcome to Dragon Quest!" << endl;
        displayDragonQuest();

        Character player;
        int alpha = 0;
        while (alpha == 0) { 
            cout << "\nChoose the type of Warrior you want to become: " << endl;
            cout << "1. Swordsman" << endl;
            cout << "2. Spartan" << endl;
            cout << "3. Wizard" << endl;
            cout << "4. Archer" << endl;
            cout << "0. Exit the game" << endl;

            int c1;             //choice 1
            cin >> c1;
            cout << endl;

            if (c1 == 0) { 
                cout << "Exiting the game. Goodbye!" << endl;
                break; 
            }

            player = selectCharacter(c1); // Select character based on user input
            if(player.type == "Swordsman"){
                displaySword();
            }
            if(player.type == "Spartan"){
                
            }
            if(player.type == "Wizard"){
                displayMage();
            }
            if(player.type == "Archer"){
                displayArcher();
            }
            displayStats(player); // Display player stats

            cout << "Good morning player you have woken up in your village!" << endl << "Your goal is to become strong enough and kill the dragon that has been tormenting the lands" << endl << "Kill mobs and trade goods to increase your stats" << endl;

            string location;
            location = "Village";
            
            int beta = 0;
            while(beta == 0){
                if(location == "Village"){
                    cout << "What do you want to do in the village?" << endl;
                    cout << "Press 1 to look for mobs" << endl;
                    cout << "press 2 to sleep and replenish Health" << endl;
                    cout << "Press 3 to travel" << endl;
                    int c2;
                    cin >> c2;          //choice 2
                    cout << endl;
                    Mob opponent;

                    switch (c2)
                    {
                    case 1:
                        cout << "a mob appeared" << endl;
                        opponent = spawnRandomMob(location);
                        if(opponent.name == "Wolf"){
                            displayWolf();
                        }
                        if(opponent.name == "Skeleton"){
                            displaySkeleton();
                        }
                        if(opponent.name == "Witch"){
                            displayWitch();
                        }
                        if(opponent.name == "Thug"){
                            
                        }
                        displayStatsMob(opponent);
                        cout << "A " << opponent.name << " stands in front of you " << endl << "Do you want to fight or run away" << endl;  
                        fight(opponent, player);
                        if(player.hp <= 0){
                            cout << " You Died!" << endl;
                            cout << "\t\t GAME OVER " << endl;
                            alpha = alpha + 1;
                            beta = beta + 1;
                        }
                        
                        break;
                    
                    case 2:
                        cout << "you heatlh has replenished" << endl;
                        player.hp = 120;
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
                        cout << "Press 2 to enter the cave" << endl;
                        cout << "Press 3 to travel " << endl;

                        int c2;
                        cin >> c2;
                        cout << endl;

                        if (c2 == 1) {
                            Mob opponent = spawnRandomMob(location);
                            if(opponent.name == "Wolf"){
                                displayWolf();
                            }
                            if(opponent.name == "Skeleton"){
                                displaySkeleton();
                            }
                            if(opponent.name == "Witch"){
                                displayWitch();
                            }
                            if(opponent.name == "Thug"){
                                
                            }
                            displayStatsMob(opponent);
                            cout << "A " << opponent.name << " approaches!" << endl;
                            fight(opponent, player); // Engage in combat
                            if(player.hp <= 0){
                                cout << " You Died!" << endl;
                                cout << "\t\t GAME OVER " << endl;
                                alpha = alpha + 1;
                                beta = beta + 1;
                            }
                        }else if(c2 == 2){
                            displayCentaur();
                            cout << "Beware you are entering the cave of Cenaturs" << endl;
                            cout << "The half human half horse is a tough beast to kill " << endl;
                            cout << "do you wish to enter?"<< endl;
                            cout << "Press y for yes and n for no" << endl;
                            char c3;
                            cin >> c3;
                            cout << endl;
                            if( c3 == 'y' || c3 == 'Y'){
                                Mob opponent = spawnCentaur(location);
                                displayStatsMob(opponent);
                                cout << "The " << opponent.name << " Bellows at you!" << endl;
                                fight(opponent, player);
                                if(player.hp <= 0){
                                    cout << " You Died!" << endl;
                                    cout << "\t\t GAME OVER " << endl;
                                    alpha = alpha + 1;
                                    beta = beta + 1;
                                }

                            }
                            else if(c3 == 'n' || c3 == 'N'){
                                cout << "you ran away" << endl;
                            }

                        } 
                        else if (c2 == 3) {
                            location = chooseLocation(); // Travel to another location
                        } else {
                            cout << "Invalid option." << endl;
                        }
                }
                else if( location == "Town"){
                    cout << "You are now in the Town. It's a peaceful place to rest and trade." << endl;
                    cout << "Press 1 to look for mobs" << endl;
                    cout << "Press 2 to buy Items" << endl;
                    cout << "Press 3 to sleep in the travern and replenish health " << endl;
                    cout << "Press 4 to travel " << endl;

                    int c2;
                    cin >> c2;
                    cout << endl;

                    if (c2 == 1) {
                        Mob opponent = spawnRandomMob(location);
                        displayStatsMob(opponent);
                        if(opponent.name == "Wolf"){
                            displayWolf();
                        }
                        if(opponent.name == "Skeleton"){
                            displaySkeleton();
                        }
                        if(opponent.name == "Witch"){
                            displayWitch();
                        }
                        if(opponent.name == "Thug"){
                            
                        }
                        cout << "A " << opponent.name << " appears!" << endl;
                        fight(opponent, player);
                        if(player.hp <= 0){
                            cout << " You Died!" << endl;
                            cout << "\t\t GAME OVER " << endl;
                            alpha = alpha + 1;
                            beta = beta + 1;
                        }
                    }
                    else if(c2 == 2) {
                        player = shop(player);
                        
                    }
                    else if(c2 == 3) {  
                        cout << "Rent for the travern is 5 coins, do you want to sleep and replenish health?" << endl;
                        char c3;
                        cout << " Press y for yes and n for no" << endl;
                        cin >> c3;
                        cout << endl;
                        if(c3 == 'y' || c3 == 'Y'){
                            if(player.purse >= 5){
                                cout << "Your health is FULL!" << endl;
                                player.purse -= 5;
                                player.hp = 120;
                                displayStats(player);
                            } 
                            else{
                                cout << "You dont have enough money, go kill some mobs" << endl;
                            }
                        }else if(c3 == 'n' || c3 == 'N'){
                            cout << "You can come back to the travern anytime to regain health" << endl;
                        }
                    } 
                    else if (c2 == 4) {
                        location = chooseLocation(); // Travel to another location
                    } else {
                        cout << "Invalid option." << endl;
                    }

                }
                else if( location == "Castle"){
                    cout << "You are at the Castle. It stands tall and mysterious." << endl;
                    cout << "Press 1 to search for mobs" << endl;
                    cout << "Press 2 to enter the dungeons" << endl;
                    cout << "Press 3 to travel to another location" << endl;

                    int c2;
                    cin >> c2;
                    cout << endl;

                    if (c2 == 1) {
                        Mob opponent = spawnRandomMob(location);
                        if(opponent.name == "Wolf"){
                            displayWolf();
                        }
                        if(opponent.name == "Skeleton"){
                            displaySkeleton();
                        }
                        if(opponent.name == "Witch"){
                            displayWitch();
                        }
                        if(opponent.name == "Thug"){
                            
                        }
                        displayStatsMob(opponent);
                        cout << "A " << opponent.name << " challenges you!" << endl;
                        fight(opponent, player);
                        if(player.hp <= 0){
                            cout << " You Died!" << endl;
                            cout << "\t\t GAME OVER " << endl;
                            alpha = alpha + 1;
                            beta = beta + 1;
                        }
                    } 
                    else if (c2 == 2){
                        displayminataur1();
                        cout << "Beware you are entering the lair of minotaurs" << endl;
                        cout << "The half human half bull is a tough beast to kill " << endl;
                        cout << "do you wish to enter?"<< endl;
                        cout << "Press y for yes and n for no" << endl;
                        char c3;
                        cin >> c3;
                        cout << endl;
                        if( c3 == 'y' || c3 == 'Y'){
                            Mob opponent = spawnMinotaur(location);
                            displayStatsMob(opponent);
                            cout << "The " << opponent.name << " Bellows at you!" << endl;
                            fight(opponent, player);
                            if(player.hp <= 0){
                                cout << " You Died!" << endl;
                                cout << "\t\t GAME OVER " << endl;
                                alpha = alpha + 1;
                                beta = beta + 1;
                            }   

                        }
                        else if(c3 == 'n' || c3 == 'N'){
                            cout << "you ran away" << endl;
                        }
                    }
                    else if (c2 == 3) {
                        location = chooseLocation(); // Travel to another location
                    } else {
                        cout << "Invalid option." << endl;
                    }
                }
                else if( location == "Dragon's Lair"){
                    cout << "Press 1 to enter the Lair" << endl;
                    cout << "Press 2 to travel to another location" << endl;
                    int c2;
                    cin >> c2;
                    cout << endl;

                    if (c2 == 1) {
                        Mob opponent = spawnDragon(location);
                        displayStatsMob(opponent);
                        cout << "The " << opponent.name << " spits fire in the sky!" << endl;
                        fight(opponent, player);
                        if(player.hp <= 0){
                            cout << " You Died!" << endl;
                            cout << "\t\t GAME OVER " << endl;
                            alpha = alpha + 1;
                            beta = beta + 1;
                        }
                        if(opponent.hp <= 0){
                            cout << "You killed the dragon!" << endl;
                            cout << "Congratulations" << endl;
                            cout << "You have successfully completed the game" << endl;
                            alpha = alpha + 1;
                            beta = beta + 1;
                        }
                    } 
                    else if (c2 == 2){
                        location = chooseLocation();
                    }
                }  
            }
            
        }
        cout << "You are dead " << endl;
        cout << "Press 1 to play again" << endl;
        cout << "Press 2 to quit" << endl;

        int c4;
        cin >> c4;
        cout << endl;
        if(c4 == 1){

        }else{
            break;
        }
        
    
    }
    return 0;
    
}
