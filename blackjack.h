
#include <iostream>
#include <vector>
#include "Game_files/window.h"
#include "Game_files/bet.h"
#include "Player_files/Dealer.h"
#include "Player_files/Human.h"
#include "Player_files/card.h"
#include "Player_files/deck.h"
#include "Player_files/Safe_dealer.h"
#include "Player_files/Risky_dealer.h"

#ifndef BLACKJACK_H
#define BLACKJACK_H

/*
    Blackjack class:
        attrs:
            private:
                balance (int of the balance that the user has initialised)
                bet_amount (int of the bet amount, initially zero, that the user sets when they start game);
                windowtools (Window from window.h, allows the production of the required cards)
                betting (Bet from bet.h, allows the game to request the bet amount and ensure that it is less than the balance)
                array (vector <WINDOW *>, ncurses type that enables the returning and storage of the buttons and cards for the screen)
        
        methods:
            public:
                std::vector<WINDOW *> game_template(); // returns the template of the cards in the window
                std::vector<WINDOW *> start_game(); // returns a an array of WINDOW types, which are composed of cards and buttons
                std::vector<WINDOW *> hit(); // returns the user's cards and the dealers cards if they hit
                std::vector<WINDOW *> stand(); // returns the dealers cards if they hit

                string winner()
                int get_bet_amount(); // from Bet
*/
class Blackjack: public Bet {

    private:
        int balance;
        int bet_amount;
        Window windowtools;
        Bet *betting;
        std::vector<WINDOW *> array;
        Human *user;
        Dealer *dealer;
        deck initialised_deck;


    public:
        Blackjack();
        Blackjack(int _balance, int chosen_dealer);
        
        std::vector<WINDOW *> game_template();
        std::vector<WINDOW *> game_template(string dealer_1, string dealer_2, 
                                            string player_1, string player_2);

        std::vector<WINDOW *> start_game(); // returns a pointer to an array of windows
        std::vector<WINDOW *> hit(int hit_number);
        std::vector<WINDOW *> stand(int stand_counter);
        string winner(); // function that returns a string of who won the game
        bool bust(); // checks if either the dealer or user is bust

        Human *gethuman();
        Dealer *getdealer();
        int usercount();
        int dealercount();


        int get_bet_amount(); // from Bet
        ~Blackjack();
};

#endif

