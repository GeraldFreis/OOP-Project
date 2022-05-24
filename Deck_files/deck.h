#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include "card.h"
using std::cout; using std::string;

/*
Class deck
    has attrs:
        array {array of the cards in the deck}
        length {integer of the current length of the deck}
        drawn_cards {array of the cards drawn from the deck}
    
    has methods:
        void fillDeck() {fills the array with all possible cards}
        void addCard(card new_card){adds a new card to the deck}
        void removeCard(int rand_num) {removes a card from the deck}
        void removeLastCard() {removes the last card drawn from the deck}
        void printInt(){prints the values of all cards}
        card drawCard(){picks a random card from the deck}
        void printCard(int deck_num){prints a given card from the deck based on formal param deck_num}
*/
class deck{
    private:
        card *array;
        int length;
        int *drawn_cards; 

    public:
        deck();

        void fillDeck();

        void addCard(card new_card);

        void removeCard(int rand_num);
        void removeLastCard();

        void printInt();


        card drawCard();

        void printCard(int deck_num);

        ~deck();

};
#endif