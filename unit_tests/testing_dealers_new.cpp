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
    int hitnumber = 0;

    srand ( time(NULL) );  
    deck initialised_deck;
    initialised_deck.fillDeck();

    card *cards = new card[4];
    for(int i = 0; i < 4; i++) {cards[i] = initialised_deck.drawCard();
                                 initialised_deck.removeLastCard();}

    Dealer *first_dealer = new Safe_dealer;
    // first_dealer->addCard(cards[0]);
    // cout << cards[0].getName();
    first_dealer->addCard(cards[0]);
    first_dealer->addCard(cards[1]);
    card *card_array = first_dealer->getCards();

    for(int i = 0; i < 5; i++){
        cout << card_array[i].getName() << " ";
    }

    
    first_dealer->setCount();
    first_dealer->Move();
    cout << first_dealer->getCount() << " " << first_dealer->getMove();

    
}