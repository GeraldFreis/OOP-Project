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

void Game::Gamescreen(){
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

    Window userwindow;

    // creating the buttons in the window
    WINDOW *hit_button;
    WINDOW *stand_button;
    WINDOW *double_button;
    WINDOW *start_button;

    bool test = true;
    int stage = 1;
    keypad(stdscr, TRUE);

    // game loop
    while (test){
        while(stage == 1){
            int input = getch();
            
            // setting up the dealer
            mvaddstr(7,89,"Dealer's cards: ");
            card_1 = userwindow.create_cards(10,70);
            card_2 = userwindow.create_cards(40,70);

            // setting up the player
            mvaddstr(37,89,"Player's cards: ");
            card_3 = userwindow.create_cards(10,100);
            card_4 = userwindow.create_cards(40,100);

            // setting up the balance
            mvaddstr(37,170, "Player balance: ");
            mvaddstr(40,170, "Bet amount: ");

            // setting up the buttons

            // start button
            mvaddstr(11, 17, "Start");
            start_button = userwindow.create_buttons(10, 10);

            // hit button
            mvaddstr(16, 18, "Hit");
            hit_button = userwindow.create_buttons(10, 15);

            // stand button
            mvaddstr(21, 17, "Stand");
            stand_button = userwindow.create_buttons(10, 20);

            // double button
            mvaddstr(26, 17, "Double");
            double_button = userwindow.create_buttons(10, 25);

            // checking if the user ends the game          
            if(input == '1'){
                test = false; // ending the game
                break;
            }
            
        }
    }
    // ending the windows
    userwindow.end_win(card_1);
    userwindow.end_win(card_2);
    userwindow.end_win(card_3);
    userwindow.end_win(card_4);
    endwin();
    return;
};

Game::~Game(){
    cout << "Thanks for playing" << "\n";
};