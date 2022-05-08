#include "game.h"
#include "window.h"

Game::Game(){
    balance = 0;
    betamount = 0;
};

Game::Game(int receivedbalance){
    balance = receivedbalance;
    betamount = 0;
};

void Game::createscreen(){
    initscr();
    clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */

    // initialising the screen and box position

    printw("Press the number 1 to exit, and the number 2 to start");
    refresh();

    // creating the cards in the window
    WINDOW *card_1;
    WINDOW *card_2;    
    WINDOW *card_3;
    WINDOW *card_4;

    bool test = true;
    int stage = 1;
    keypad(stdscr, TRUE);

    // game loop
    while (test){
        while(stage == 1){
            int input = getch();
            Window userwindow;

            mvaddstr(7,85,"Dealer's cards: ");
            card_1 = userwindow.create_cards(10,70);
            card_2 = userwindow.create_cards(40,70);

            mvaddstr(37,85,"Player's cards: ");
            card_3 = userwindow.create_cards(10,100);
            card_4 = userwindow.create_cards(40,100);

            // game loop
            
            if(input == '1'){
                test = false;
                break;
            }
            
        }
    }
    
    endwin();
};

Game::~Game(){
    cout << "Thanks for playing" << "\n";
};