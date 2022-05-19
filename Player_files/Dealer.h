#include <iostream>
#include "person.h"
#include "deck.h"
#include "card.h"
using std::cout; using std::string; using std::cin;

#ifndef DEALER_H
#define DEALER_H

class Dealer: public Person {
    private:
        int card_total;
        card *card_array;
        string last_move;
        //string choosen_move;
        

    public:
        Dealer();                       
        virtual void Move() = 0;
        void addCardDealer(card new_card);

        void printCardDealer(int num);
        

        // int getCountDealer();
        
        // string getMoves();    
        // string getMove();
        // void hit(); 
                                          
        virtual ~Dealer();
};

#endif