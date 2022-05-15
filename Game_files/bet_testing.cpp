#include <iostream>
#include "bet.h"
using std::cout;

int main(){
    Bet betwindow(1000);
    
    betwindow.set_bet_amount();
    cout << betwindow.get_bet_amount() << "\n";

}