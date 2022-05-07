#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

class deck{
    private:
        card *array;
        int length;

    public:
        deck();

        void fillDeck();

        void addcard(card new_card);

        void printCard(int deck_num);

        ~deck();

};
#endif