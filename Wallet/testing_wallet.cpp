#include <iostream>
#include "wallet.h"
using std::cout; using std::string;

int main(){
    Wallet wallet;
    wallet.retreivebalance();
    cout << "Current balance: " << wallet.getbalance() << "\n";

    cout << "\nChanging the current balance" << "\n";

    int given_balance = 200;
    wallet.setbalance(given_balance);
    cout << "Balance should be: " << given_balance << "\n";
    wallet.retreivebalance();
    cout << "Current balance: " << wallet.getbalance() << "\n";

    cout << "\nChanging the current balance" << "\n";

    int updated_balance = 3300;
    wallet.setbalance(updated_balance);
    cout << "Balance should be: " << updated_balance << "\n";
    wallet.retreivebalance();
    cout << "Current balance: " << wallet.getbalance() << "\n";

    return 0;
}
