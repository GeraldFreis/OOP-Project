#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "deck.h"
#include "card.h"

/*
Superclass / base class of Dealer and Human
    has attrs:
        card_total (int) {relates to the sum of the values of the cards in hand}
        card_array (card*) {an array of card objects that the Dealer has been given}
        last_move (string) {a string "hit" or "stand" of the dealer's last move}
        last_card {a string of the last card in hand}
        number_of_cards; {the number of cards in the card_array}
    
    has methods:
        public:
            setCount() {updates the count / card_total of the dealer }
            addCard(card new_card) {adds a card to the dealer's hand}
            getCards(); {returns the card_array}
            lastCard(); {returns the last card in the card_array}
            setMove(string move); {sets the last_move to the move given}
            bool winGame(); {checks if the dealer is bust}
            virtual ~Person() {virtual destructor}
            
*/
class Person {
    private:
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
        card *getCards();
        
        string lastCard();
        void setMove(string move);
        //void hit();

        bool winGame();
        virtual ~Person();
};

#endif