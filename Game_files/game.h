#include <iostream>
#include <ncurses.h>
#include <string.h>
using std::cout; using std::string; using std::cin;

#ifndef GAME_H
#define GAME_H

/*
    Game objects create the ncurses screen / interface
        interface includes:
            player and dealers' cards, player's balance, player's bet amount, and buttons controlling actions
    
    attrs
        int balance
        int betamount
    
    methods
        Gamescreen // creates the UI for the game
*/
class Game {
    private:
        int balance;
        int betamount;

    public:
        Game(); // default constructor 
        Game(int receivedbalance); // parameterized constructor taking user balance

        void Gamescreen(); // function to create the screen and cards

        ~Game();
};

#endif