#include <iostream>
#include <string>
#include <ncurses.h>
#include "card.h"
#include "deck.h"
#include "Game_files/game.h"
#include "Wallet/wallet.h"
using namespace std;

int main(){

    Wallet users_wallet("users_balances.txt");
    users_wallet.read();
    
    Game userinstance(users_wallet.getbalance());
    userinstance.Gamescreen();
    
    deck d1;
    d1.fillDeck();

    for(int i=0; i<52; i++){
        d1.printCard(i+1);
    }

    return 0;
}
