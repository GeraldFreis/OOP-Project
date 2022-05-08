#include <ncurses.h>
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
        createscreen // creates the UI
        endgame // destroys the UI
*/
class Game {
    private:
        int balance;
        int betamount;

    public:
        Game(); // default constructor 
        Game(int receivedbalance); // parameterized constructor taking user balance

        void createscreen(); // function to create the screen and cards
        void updatescreen();
        void endgame();
};

#endif