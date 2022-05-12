#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include "card.h"
using std::cout; using std::string;

class deck{
    private:
        card *array;
        int length;

    public:
        deck();

        void fillDeck();

        void addCard(card new_card);

        void removeCard(int rand_num);

        card drawCard();

        void printCard(int deck_num);

        ~deck();

};
#endif