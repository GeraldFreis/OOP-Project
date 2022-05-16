#include "blackjack.h"
#include "Player_files/Human.h"
#include "Player_files/card.h"

#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::string;

int main() {
    Blackjack blackjack;
    // blackjack.start_game();
    int hitnum = 0;
    vector<WINDOW *> win = blackjack.hit(hitnum);
    hitnum++;
    if(blackjack.bust()){
        cout << "Test 1 failed" << "\n";
    }
    else {
        cout << "Test 1 passed" << "\n";
    }

    win = blackjack.hit(hitnum);
    Human *user = blackjack.gethuman();
    Dealer *dealer = blackjack.getdealer();
    user->setCount();
    dealer->setCount();
    hitnum++;
    
    if(blackjack.bust() && (user->getCount() < 21 && dealer->getCount() < 21)) {
        cout << "Test 2 failed (the user and dealer were not over 21" << "\n";
    }
    else {
        cout << "Test 2 passed" << "\n";
    }

    win = blackjack.hit(hitnum);
    user = blackjack.gethuman();
    dealer = blackjack.getdealer();
    user->setCount();
    dealer->setCount();
    hitnum++;
    if(blackjack.bust() && (user->getCount() < 21 && dealer->getCount() < 21)) {
        cout << "Test 3 failed (the user and dealer were not over 21)" << "\n";
    }
    else {
        cout << "Test 3 passed" << "\n";
    }
     win = blackjack.hit(hitnum);
    user = blackjack.gethuman();
    dealer = blackjack.getdealer();
    user->setCount();
    dealer->setCount();

    if(blackjack.bust() && (user->getCount() < 21 && dealer->getCount() < 21)) {
        cout << "Test 4 failed (the user and dealer were not over 21)" << "\n";
    }
    else {
        cout << user->getCount() << " " << dealer->getCount() << "\n";
        cout << "Test 4 passed" << "\n";
    }

    return 0;
}