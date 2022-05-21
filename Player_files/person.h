#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "deck.h"
#include "card.h"

class Person {
    protected:
        card *card_array;
        int card_total;
        string lastcard;
        string last_move;
        int number_of_cards;
    
    public:
        Person();
        
        string getMove();
        int getCount();

        void setCount();
        void addCard(card new_card);
        int addCard();
        card *getCards();
        
        string lastCard();
        void setMove(string move);
        //void hit();

        bool winGame();
        virtual ~Person();
};

#endif