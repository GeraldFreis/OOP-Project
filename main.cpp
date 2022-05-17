#include <iostream>
#include "game.h"
#include "Wallet/wallet.h"
using std::cout; using std::string;

int main() {
    // setting up the wallet
    Wallet user_funds("users_balances.txt");
    user_funds.read();

    // initialising the game window
    Game game(user_funds.getbalance());
    game.mainscreen(); // game window
    // cout << game.get_balance();
    user_funds.setbalance(game.get_balance());
    user_funds.write();
}

