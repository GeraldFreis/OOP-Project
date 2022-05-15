#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "person.h"
#include "Dealer.h"
#include "Human.h"
#include "deck.h"
#include "card.h"

using namespace std;

int main(){
//create a deck to use to play
    srand ( time(NULL) );  
    deck d1;
    d1.fillDeck();

//draws 20 cards, removes each of those 20 cards, prints out all cards 
    // for(int i=0; i<20; i++){
    //     cout << d1.drawCard().getName() << endl; 
    //     d1.removeLastCard();
    // }
    // for(int j=0; j<312; j++){
    //     d1.printCard(j);
    // }

//create a dealer and a human
    Dealer dealer1;
    Human player1;    

//deal cards, 2 to player, 1 to dealer 
    //2 cards to player 
    cout << "Players cards: " << endl;
    card c1;
    //card 1
    c1 = d1.drawCard();
    player1.addCardHuman(c1);
    d1.removeLastCard();
    player1.printCardHuman(1);
    //card 2
    c1 = d1.drawCard();
    player1.addCardHuman(c1);
    d1.removeLastCard();
    player1.printCardHuman(2);

    //dealer card 1
    cout << "Dealers card: " << endl;
    c1 = d1.drawCard();
    dealer1.addCardDealer(c1);
    d1.removeLastCard();
    dealer1.printCardDealer(1);

// player chooses to hit until they stand
    char choice = ' ';
    int j=0;
    bool bust = false;
    bool blackjack = false;
    while(choice!='N' || choice!='n'){
        cout << "Would you like to hit? (Y/N)" << endl;
        cin >> choice;
        if(choice=='N' || choice=='n'){
            break;
        }
        if(choice!='Y' || choice!='y'){
            c1 = d1.drawCard();
            player1.addCardHuman(c1);
            d1.removeLastCard();
            player1.printCardHuman(j+3);
            j++;
            //check whether the player exceeds 21
            if(player1.getCountHuman() > 21){
                cout << "total: " << player1.getCountHuman() << " Bust " << endl;
                bust = true;
                break;
            }
            else if(player1.getCountHuman() == 21){
                cout << "total: " << player1.getCountHuman() << " BlackJack " << endl;
                blackjack = true;
                break;
            }
            else{
                cout << "total: " << player1.getCountHuman() << endl;

            }
        }
        else{
            cout << "invalid entry" << endl;
        }
    } 

//dealer plays if the player is still in play
    if(bust==false && blackjack==false){
        bool stand = false;
        bool dealer_win = false;
        
        cout << "Dealers draw: " << endl;
        int l=0;
        for(int k=0; k<5; k++){
            //dealer gets another card
            c1 = d1.drawCard();
            dealer1.addCardDealer(c1);
            d1.removeLastCard();
            dealer1.printCardDealer(2+l);
            l++;
        
            //check dealers total 
            if(dealer1.getCountDealer() < 22){
                if(dealer1.getCountDealer() > player1.getCountHuman()){
                    dealer_win = true;
                    cout << "Dealer total: " << dealer1.getCountDealer() << endl;
                    break;
                }
                else if(dealer1.getCountDealer() == player1.getCountHuman()){
                    stand = true;
                    cout << "Dealer total: " << dealer1.getCountDealer() << endl;
                    break;
                }
            }
            else{
                cout << "Dealer total: " << dealer1.getCountDealer() << endl;
                cout << "dealer bust" << endl;
                break;
            }
        }

    }




    return 0;
}