#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include "deck.h"
#include "card.h"
#include "person.h"
using namespace std;


/* class Human inherits from public of class Person
    Human has attrs / data members:
        card_total {is the sum of values of the cards in hand}
        card_array {array of card objects given to the human object }
        number_of_cards {number of cards in the hand (updated after every addCard function is called)};
        last_move {last move the player made}
    
    public methods:
        getLastCard(){returns the last card given to the human object}

        inherited:
            setCount() {updates the count / card_total of the dealer }
            addCard(card new_card) {adds a card to the dealer's hand}
            getCards(); {returns the card_array}
            lastCard(); {returns the last card in the card_array}
            setMove(string move); {sets the last_move to the move given}
            bool winGame(); {checks if the dealer is bust}
*/
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
        // void Move();
        card getLastCard();
        //card hit(card n_card);
        
        //void playerMove();

        //string getMoves();    
                                  
        ~Human();
};

#endif