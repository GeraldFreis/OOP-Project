#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include "deck.h"
#include "card.h"
#include "person.h"
using namespace std;


class Human: public Person {
    private:
        int card_total;
        card *card_array;
        int number_of_cards;
        string last_move;
        //string choosen_move;
        

    public:
        Human();   

        void addCardHuman(card n_card);

        void printCardHuman(int num);                   
        
        // int getCountHuman();
        void Move();
        card getLastCard();
        //card hit(card n_card);
        
        //void playerMove();

        //string getMoves();    
                                  
        ~Human();
};

#endif