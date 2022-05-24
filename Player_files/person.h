#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "../Deck_files/deck.h"
#include "../Deck_files/card.h"

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
            card *getCards() {returns the cards that the object of this class has}
            lastCard(); {returns the last card in the card_array}
            setMove(string move); {sets the last_move to the move given}
            bool winGame(); {checks if the object is bust and returns false (i.e they can not win the game)}
            virtual ~Person() {virtual destructor}
            
*/
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