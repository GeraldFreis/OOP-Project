#include <iostream>
#include "../../blackjack.h"
#include "../../Player_files/Dealer.h"
#include "../../Player_files/Risky_dealer.h"
#include "../../Player_files/Safe_dealer.h"
#include "../../Deck_files/card.h"
#include "../../Deck_files/deck.h"
#include "../../Player_files/Human.h"

using std::cout; using std::string;

int main(){
    // testing the risky dealer
    int hitnumber = 0;

    srand ( time(NULL) );  
    deck initialised_deck;
    initialised_deck.fillDeck();

    card *cards = new card[4];
    for(int i = 0; i < 4; i++) {cards[i] = initialised_deck.drawCard();
                                 initialised_deck.removeLastCard();}

    Dealer *dealer_1 = new Risky_dealer();
    dealer_1->addCard(cards[0]);
    dealer_1->addCard(cards[1]);
    dealer_1->setCount();

    // testing if the dealer functions are correct when determining what the dealer needs to do
    dealer_1->Move();
    if(dealer_1->getCount() ==21 && dealer_1->getMove() != "stand"){
        cout << "Test 1 failed (dealer did not stand)\n";
        cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";
    }
    else {
        cout << "Test 1 passed (dealer did stand)\n";
        cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";
    }

    // giving the safe dealer another card and seeing if they are bust
    dealer_1->addCard(cards[2]);
    dealer_1->setCount();
    dealer_1->Move();
    dealer_1->setCount();

    if(dealer_1->winGame() != false) {

        if(dealer_1->getCount() > 21){
            cout << "Test 2 failed (dealer is bust and wingame did not report it..)" << "\n";
            cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";
        }
        else if(dealer_1->getCount() == 21 && dealer_1->getMove() != "stand"){
            cout << "test 2 failed (dealer is not bust but was at 21 and didn't stand" << "\n";
            cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";
        }
        else {
            cout << "Test 2 passed" << "\n";
            cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";
        }
    }

    else if(dealer_1->winGame() == false && dealer_1->getCount() <= 21){
        cout << "Test 2 failed (dealer was not bust and wingame reported it as bust)" << "\n";
        cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";
    }

    else if(dealer_1->winGame() == true && dealer_1->getCount() <= 21){
        cout << "Test 3 passed (dealer was beneath the card limit and wingame was false" << "\n";
        cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";
    }

    else if(dealer_1->winGame() == false && dealer_1->getCount() > 21){
        cout << "Test 3 passed (dealer was above limit and wingame was true)" << "\n";
        cout << dealer_1->getMove() << " " << dealer_1->getCount() << "\n";

    }
}