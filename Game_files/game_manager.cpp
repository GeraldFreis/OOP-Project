#include "game_manager.h"

Game_manager::Game_manager(int _balance){
    balance = _balance;
    draw = false;
    stage = 0;
    test = true;
    given_dealer = 0;
}

Game_manager::Game_manager(){
    balance = 0;
    draw = false;
    stage = 0;
    test = true;
    given_dealer = 0;
}

// setting the balance of the user
void Game_manager::setbalance(int _balance){
    balance = _balance;
}

// calculating the new balance of the user
void Game_manager::calcbalance(int bet_amount, Blackjack *blackjack){
    Dealer *dealer = blackjack->getdealer();
    Human *user = blackjack->gethuman();
    dealer->setCount();
    user->setCount();
    if(dealer->getCount() > 21 && user->getCount() > 21 || dealer->winGame() == false && user->winGame() == false){
        balance = balance - bet_amount;
    }
    else if(dealer->getCount() > 21){ 
        balance = balance + bet_amount;
    }
    else if(user->getCount() > 21){ 
        balance = balance - bet_amount;
    }
    else if(dealer->getCount() > user->getCount()) { 
        balance = balance - bet_amount;
    }
    else if(user->getCount() < dealer->getCount() && user->winGame() == true) {
        balance = balance + bet_amount;
    }
    else if(user->winGame() == false && dealer->winGame() != false){
        balance = balance - bet_amount;
    }
    else {
        draw = true;
    }
}

// function to capture the initial input of the user
bool Game_manager::initial_user_input(){
    bool test_var = true;
    this->test = true;
    while(test_var == true){

        if(balance == 0){ // if the user has no money
            mvaddstr(5, 10, "                         ");
            // mvaddch(5, 40, ' ');
            printw("You do not have sufficient funds to play (HIT ESC To exit)");
            printw("    Balance: ");
            printw(std::to_string(balance).c_str());
        }
        //get input from user to continue 
        int key_input = getch();
        switch (key_input)
            {
            case KEY_ESC:
                this->test = false;
                stage = 0;
                test_var = false;
                break;

            case ' ':
                if(balance != 0){
                    stage = 1;
                    test_var = false;
                }
                break;

            case '4':
                if(balance != 0){
                    given_dealer = 1;
                    stage = 1;
                    test_var = false;
                }
                break;
            
            case '5':
                if(balance != 0){
                    given_dealer = 0;
                    stage = 1;
                    test_var = false;
                }
                break;

            default:
                break;
            }
    }
    return this->test;
}

// interface to show when the game has ended
void Game_manager::endgame_interface(Game_manager *manager, Blackjack *blackjack, std::vector<WINDOW *> screen_object_arr){

    bool while_test = true;
    
    while(while_test == true){
        manager->setbalance(balance);
        manager->calcbalance(blackjack->get_bet_amount(), blackjack);
        balance = manager->getbalance();
        
        // if it is a draw then we show the draw things on the screen
        if(manager->isdraw() == true){
            if(blackjack->winner() == "dealer"){ // if both the player and dealer are bust
                mvaddstr(33, 85, "Totals of user vs dealer: ");
                printw(std::to_string(blackjack->gethuman()->getCount()).c_str());
                printw(" vs ");
                printw(std::to_string(blackjack->getdealer()->getCount()).c_str());
                mvaddstr(30, 88, "Dealer won as user was bust");
            }// if both the player and dealer have the same card total
            else {
                 mvaddstr(30, 90, "No winner. Bet returned.");
            }
        } // if one of the two win
        else{   
            mvaddstr(30, 90, "The winner was: ");
            printw( blackjack->winner().c_str());
            mvaddstr(33, 85, "Totals of user vs dealer: ");
            printw(std::to_string(blackjack->gethuman()->getCount()).c_str());
            printw(" vs ");
            printw(std::to_string(blackjack->getdealer()->getCount()).c_str());
        } 
        nodelay(stdscr, FALSE);

        int key_input = getch();
        switch (key_input)
        {
        case KEY_ESC:
            stage++;
            test = false;
            while_test = false;
            break;
        default:
            stage += 1;
            while_test = false;
            endwin();
            break;
        }
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

bool Game_manager::gettest(){
    return test;
}
// function to return the stage of the game
int Game_manager::getstage(){
    return stage;
}

// getting the chosen dealer
int Game_manager::get_chosen_dealer(){
    return given_dealer;
}

void Game_manager::setdraw(){
    draw = false;
}