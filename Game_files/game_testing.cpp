#include <iostream>
#include "game.h"

int main(){
    Game game(1000);
    game.mainscreen();
    cout << game.get_bet_amount();
}