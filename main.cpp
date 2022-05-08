#include <iostream>
#include <string>
#include <ncurses.h>
#include "card.h"
#include "deck.h"
#include "game.h"
using namespace std;

int main(){

    deck d1;
    d1.fillDeck();

    for(int i=0; i<52; i++){
        d1.printCard(i+1);
    }

    Game userinstance;
    userinstance.createscreen();
    
    return 0;
}
