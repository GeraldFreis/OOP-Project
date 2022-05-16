#include "blackjack.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::string;

int main() {
    Blackjack blackjack;
    int hitnum = 0;
    cout << blackjack.usercount();
    std::vector<WINDOW*> winvecs = blackjack.hit(hitnum);
    cout << blackjack.usercount();
    // if(blackjack.bust()) // if the user or dealer is bust
    // {
    //     cout << "Test 1 failed" << "\n";
    // }
    // else 
    // {
    //     cout << "Test 1 passed" << "\n";
    // }

    // hitnum ++; // increasing the hit number
    // winvecs = blackjack.hit(hitnum);
    // if(blackjack.bust()){
    //     cout << "Test 2 failed" << "\n";
    // }
    // else {
    //     cout << "Test 2 passed" << "\n";
    // }

    // hitnum ++; // increasing the hit number
    // winvecs = blackjack.hit(hitnum);
    // if(blackjack.bust() == true){
    //     cout << "test 3 passed" << "\n";
    // }
    // else {
    //     cout << "test 3 failed" << "\n";
    // }

    // hitnum ++; // increasing the hit number
    // winvecs = blackjack.hit(hitnum);
    // bool returnval = blackjack.bust();
    // if(returnval == true){
    //     cout << "test 4 passed" << "\n";
    // }
    // else {
    //     cout << "test 4 failed" << "\n";
    // }

    // hitnum++; // increasing the hit number
    // winvecs = blackjack.hit(hitnum);
    // returnval = blackjack.bust();
    // if(returnval == true){
    //     cout << "test 5 passed" << "\n";
    // }
    // else {
    //     cout << "test 5 failed" << "\n";
    // }

    // cout << blackjack.bust() << "\n";

    return 0;
}