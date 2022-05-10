#include <iostream>
#include "wallet.h"
using std::cout; using std::string;

int main(){
    Wallet wallet;
    wallet.retreivebalance();
    cout << "Balance should be 1000" << "\n";
    cout << "Current balance: " << wallet.getbalance() << "\n";

    cout << "\nChanging the current balance" << "\n";
    wallet.setbalance(200);
    cout << "Balance should be 200" << "\n";
    wallet.retreivebalance();
    cout << "Current balance: " << wallet.getbalance() << "\n";

    
    return 0;
}
