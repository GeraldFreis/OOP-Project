#include <iostream>
#include <ncurses.h>
#include <form.h>
#include <string.h>
#include "window.h"
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
        bool game_has_begun;
        int hit_counter;

        WINDOW *card_1; // dealer card 1 
        WINDOW *card_2;  // dealer card 2
        WINDOW *card_3; // player card 1
        WINDOW *card_4; // player card 2
        WINDOW *card_5; // dealer card 3
        WINDOW *card_6; // dealer card 4
        WINDOW *card_7; // player card 3
        WINDOW *card_8; // player card 4;

        Window userwindow;

        // creating the buttons in the window
        WINDOW *hit_button;
        WINDOW *stand_button;
        WINDOW *double_button;
        WINDOW *start_button;
        
        // initialising the betting window:
        WINDOW *betting_window;
        FIELD *betamount_field[2]; // initialising the field to hold the bet amount
        FORM *betting_form; // initialising the form to hold the bet amount

    public:
        Game(); // default constructor 
        Game(int receivedbalance); // parameterized constructor taking user balance

        void Gamescreen(); // function to create the screen and cards

        ~Game();
};

#endif