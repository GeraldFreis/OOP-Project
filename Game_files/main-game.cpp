#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include "game.h"


int main(){

    Game userinstance(1000);
    userinstance.Gamescreen();
    std::cout << userinstance.get_bet_amount();
}