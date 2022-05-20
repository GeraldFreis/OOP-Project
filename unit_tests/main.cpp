#include <iostream>
#include "../blackjack.h"
#include "../Player_files/Dealer.h"
#include "../Player_files/Risky_dealer.h"
#include "../Player_files/Safe_dealer.h"
#include "../Deck_files/card.h"
#include "../Deck_files/deck.h"
#include "../Player_files/Human.h"
using std::cout; using std::string;

int main(){
    Dealer *dear_1 = new Safe_dealer;
    srand ( time(NULL) );  
    deck initialised_deck;
    initialised_deck.fillDeck();

    card *cards = new card[4];
    for(int i = 0; i < 4; i++) {cards[i] = initialised_deck.drawCard();
                                 initialised_deck.removeLastCard();}
    
    dear_1->addCard(cards[0]);

    dear_1->Move();
    cout << dear_1->getMove();

}