#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "card.h"
#include "deck.h"
//#include "Game_files/game.h"
using namespace std;

// int main(){
//     // Game userinstance;
//     // userinstance.createscreen();
//     srand ( time(NULL) );           // must be included in main function to generate the seed 
// #include "Game_files/game.h"
// #include "Wallet/wallet.h"
// using namespace std;

int main(){

    // Wallet users_wallet("users_balances.txt");
    // users_wallet.read();
    
    // Game userinstance(users_wallet.getbalance());
    // userinstance.Gamescreen();
    
    srand ( time(NULL) );           // must be included in main function to generate the seed 

    deck d1;
    d1.fillDeck();

    // for(int i=0; i<312; i++){
    //     d1.printCard(i+1);
    // }

    for(int i=0; i<20; i++){
        cout << d1.drawCard().getName() << endl; //create a variable top store last card, useful to remove latest card 
        d1.removeLastCard();

    }
    
    for(int j=0; j<312; j++){
        d1.printCard(j);

    }


    return 0;
}
