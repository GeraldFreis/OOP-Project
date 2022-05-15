#ifndef DEALER_H
#define DEALER_H
#include <iostream>
#include "person.h"
#include "deck.h"
#include "card.h"
using std::cout; using std::string; using std::cin;



class Dealer{
    private:
        int card_total;
        card *card_array;
        //string choosen_move;
        

    public:
        Dealer();                       
        
        void dealerMove();

        void addCardDealer(card new_card);

        void printCardDealer(int num);
        
        int getCountDealer();

        card *getCards();
        
        // string getMoves();    

        // void hit(); 
                                          
        ~Dealer();
};

#endif