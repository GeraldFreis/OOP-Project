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

//create a dealer and a human 
    Dealer dealer1;
    Human player1;  

//get the player to place a bet 
    double wallet = 1000;
    double bet = 0;  

//while loop to run so player can play again 
    char play = 'y';
    while (play=='y' || play=='Y'){
        cout << endl;
        cout << endl;
        cout << "Would you like to play BlackJack? (Y/N)" << endl;
        cin >> play;
        if(play=='N' || play=='n'){
            break;
        }

        cout << "Balance: $" << wallet << endl;
        cout << "How much would you like to bet? ";
        while(bet < 1){
            cin >> bet;
            if(bet < 1){
                cout << "enter a valid bet" << endl;
            }
            else if(bet > wallet){
                cout << "insufficient funds" << endl;
                bet =0;
            }
        }
        cout << "bet of $" << bet << " accepted" << endl;
        cout << endl;
        wallet = wallet - bet;

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
        bool stand = false;
        bool dealer_win = false;
        bool dealer_lost = false;
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
                    dealer_lost = true;
                    break;
                }
            }

        }

    //compares outcome to see how much the player won or lost 
        double profit = 0;
        if(blackjack == true ){
            profit = bet*2.5; 
        }
        else if(stand == true){
            profit = bet;
        }
        else if(dealer_lost == true){
            profit = bet*2;
        }
        wallet = wallet + profit;
        bet = 0;
        player1.~Human();
        dealer1.~Dealer();
    }

    return 0;
}