#include <iostream>
#include "wallet.h"
using std::cout; using std::string;

int main(){
    Wallet wallet;
    wallet.retreivebalance();
    cout << wallet.getbalance();
    return 0;
}
