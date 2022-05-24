#include <iostream>
#include "../../Game_files/bet.h"
using std::cout;

int main(){
    Bet betwindow(1000);
    
    betwindow.set_bet_amount();
    // if the bet amount is greater than the balance we have an error as the code should prevent against this
    if(betwindow.get_bet_amount() > 1000){
        cout << "Test 1 failed" << "\n";
    }
    else {
        cout << "Test 1 passed" << "\n";
    }

    Bet betwindow_2(-100); // if a negative is entered the balance is reset to zero
    if(betwindow_2.get_balance() != 0){
        cout << "Test 2 failed" << "\n";
        cout << betwindow_2.get_balance();
    }
    else {
        cout << "Test 2 passed" << "\n";
    }

    Bet betwindow_3(10000);
    betwindow_3.set_bet_amount();
    if(betwindow_3.get_bet_amount() <= 10000){
        cout << "Test 3 passed" << "\n";
    }
    else {
        cout << "Test 3 failed" << "\n";
    }
}