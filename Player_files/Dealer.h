#include <iostream>
#include "person.h"
#include "deck.h"
#include "card.h"
using std::cout; using std::string; using std::cin;

#ifndef DEALER_H
#define DEALER_H

/* class Dealer (abstract) inherits public methods from Person class 
has attrs:
    card_total (int) {relates to the sum of the values of the cards in hand}
    card_array (card*) {an array of card objects that the Dealer has been given}
    last_move (string) {a string "hit" or "stand" of the dealer's last move}

has public methods:
    pure virtual Move() --> initialised in sub classes Risky_dealer and Safe_dealer

    inherits:
        setCount() {updates the count / card_total of the dealer }
        addCard(card new_card) {adds a card to the dealer's hand}
        getCards(); {returns the card_array}
        lastCard(); {returns the last card in the card_array}
        setMove(string move); {sets the last_move to the move given}
        bool winGame(); {checks if the dealer is bust}

*/
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

        // void hit(); 
                                          
        virtual ~Dealer();
};

#endif