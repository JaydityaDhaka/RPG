#include "characters.h"
#include<iostream>

using namespace std;

void shop(Character player){
    cout << "Welcome to shop!" << endl << endl;
    while(true){
        
        
        cout << "what would you like to buy?" << endl;
        cout << "press 1 to upgrade Weapon" << endl;
        cout << "press 2 to upgrade shield" << endl;
        cout << "press 3 to upgrade boots" << endl;
        cout << "press 4 to drink potions" << endl;
        cout << "press 5 to buy a horse" << endl;
        cout << "press 0 to leave the shop" << endl;

        int c1;             // choice 
        cin >> c1;
        if(c1 == 0){
            cout << "Visit again!" << endl;
            break;
        }
        else if(c1 == 1){
            cout << "Press 1 to clean the weapon (+5 Attack)      -50 coins" << endl;
            cout << "Press 2 to sharpen the weapon (+10 Attack)   -100 coins" << endl;
            cout << "Press 3 to buy a new weapon (+20 Attack)     -175 coins" << endl;
            cout << "press 0 to go back" << endl;

            int c2;
            cin >> c2;
            if( c2 == 1){
                if(player.purse >=50){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 2){
                if(player.purse >=100){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 3){
                if(player.purse >=150){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }

        }
        else if( c1 == 2){
            cout << "Press 1 to clean the shield (+5 defense)       -50 coins" << endl;
            cout << "Press 2 to reinforce the shield (+10 defense)  -100 coins" << endl;
            cout << "Press 3 to buy a new shield (+20 defense)      -175 coins" << endl;
            cout << "press 0 to go back" << endl;
            

            int c2;
            cin >> c2;
            if( c2 == 1){
                if(player.purse >=50){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 2){
                if(player.purse >=100){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 3){
                if(player.purse >=150){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
        }
        else if( c1 == 3){
            cout << "Press 1 to clean the boots (+5 Agility)      -50 coins" << endl;
            cout << "Press 2 to repair the boots (+10 Agility)    -100 coins" << endl;
            cout << "Press 3 to buy new boots (+20 Attack)        -175 coins" << endl;
            cout << "press 0 to go back" << endl;

            int c2;
            cin >> c2;
            if( c2 == 1){
                if(player.purse >=50){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 2){
                if(player.purse >=100){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 3){
                if(player.purse >=150){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
        }
        else if( c1 == 4){

            cout << "Press 1 to drink common Ale (+2 Attack)       -20 coins" << endl;
            cout << "Press 2 to drink magic potion (+2 Magic)      -50 coins" << endl;
            cout << "Press 3 to drink mountain brew Ale (+2 Attack & Defense)     -50 coins" << endl;
            cout << "press 0 to go back" << endl;

            int c2;
            cin >> c2;
            if( c2 == 1){
                if(player.purse >=20){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 2){
                if(player.purse >=50){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if( c2 == 3){
                if(player.purse >=50){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
        }
        else if( c1 == 5){
            cout << "A horse makes all your travel free and increase your agility by 5          -200" << endl; 
            cout << "Press y for yes and n for no" << endl;
            char c2;
            cin >> c2;
            if( c2 == 'y' || c2 == 'Y'){
                if(player.purse >=20){

                }else{
                    cout << "You dont have enough coins, go kill some mobs " << endl;
                }
            }
            else if(c2 == 'n' || c2 == 'N'){
                
            }
        }

    }
}
    