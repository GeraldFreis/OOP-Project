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
void Game_manager::calcbalance(int bet_amount, Blackjack *blackjack){

    if(blackjack->getdealer()->getCount()>21 || blackjack->gethuman()->getCount() > blackjack->getdealer()->getCount()) {
        balance = balance + bet_amount;
    }
    else if(blackjack->gethuman()->getCount()>21 || blackjack->gethuman()->getCount() < blackjack->getdealer()->getCount()) {
        balance = balance - bet_amount;
    }
    else {
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