#include "game_manager.h"

Game_manager::Game_manager(int _balance){
    balance = _balance;
    draw = false;
    stage = 0;
    test = true;
}

Game_manager::Game_manager(){
    balance = 0;
    draw = false;
    stage = 0;
    test = true;
}

// setting the balance of the user
void Game_manager::setbalance(int _balance){
    balance = _balance;
}

// calculating the new balance of the user
void Game_manager::calcbalance(int bet_amount, Blackjack *blackjack){

    if(blackjack->getdealer()->getCount() > 21 || blackjack->gethuman()->getCount() > blackjack->getdealer()->getCount()) {
        balance = balance + bet_amount;
    }
    else if(blackjack->gethuman()->getCount()>21 || blackjack->gethuman()->getCount() < blackjack->getdealer()->getCount()) {
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
                stage = 1;
                test_var = false;
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
        
        if(manager->isdraw() == true){
            mvaddstr(30, 90, "No winner. Bet returned.");
        }
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