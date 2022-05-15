#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include "person.h"
#include "deck.h"
#include "card.h"
using namespace std;




class Human {
    private:
        int card_total;
        card *card_array;
        string choosen_move;
        

    public:
        Human();   

        void addCardHuman(card n_card);

        void printCardHuman(int num);                   
        
        int getCountHuman();
        
        //card hit(card n_card);
        
        void playerMove();

        string getMoves();    

        
    
        
                                          
        ~Human();
};

#endif