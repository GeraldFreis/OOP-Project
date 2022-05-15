#ifndef DEALER_H
#define DEALER_H
#include <iostream>
using std::cout; using std::string; using std::cin;
#include "person.h"
#include "card.h"



class Dealer{
    private:
        int card_total;
        card *card_array;
        string choosen_move;
        

    public:
        Dealer();                       
        
        void dealerMove();

        void addCardDealer(card new_card);

        void printCardDealer(int num);
        
        int getCountDealer();
        
        string getMoves();    

        void hit();
    
        
                                          
        ~Dealer();
};

#endif