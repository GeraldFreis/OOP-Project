#include "game_manager.h"

Game_manager::Game_manager(int _balance){
    balance = _balance;
    draw = false;
}

Game_manager::Game_manager(){
    balance = 0;
    draw = false;
}

// setting the balance of the user
void Game_manager::setbalance(int _balance){
    balance = _balance;
}

// calculating the new balance of the user
void Game_manager::calcbalance(int bet_amount, Human *user, Dealer *house){
    if(house->getCount() > 21 || user->getCount() > house->getCount()) {
        balance = balance + bet_amount;
    }
    else if(user->getCount() > 21 || user->getCount() < house->getCount()) {
        balance = balance - bet_amount;
    }
    else { // if the user and dealer are equal
        draw = true;
    }
}
// returning the new balance of the user
int Game_manager::getbalance(){
    return balance;
}
//checking if the game was a draw
bool Game_manager::isdraw(){
    return draw;
}