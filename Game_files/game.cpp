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

    printw("Press the number 1 to exit, and any other key to move to the game window");
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
    
    // initialising the betting window:
    WINDOW *betting_window;
    FIELD *betamount_field[2]; // initialising the field to hold the bet amount
    FORM *betting_form; // initialising the form to hold the bet amount
    int betting_input;
    bool betting_test;
    string raw_betamount;

    bool test = true;
    int stage = 1;

    // game loop
    while (test){
        while(stage == 1){
            keypad(stdscr, TRUE);
            int input = getch();
            
            string balance_string = std::to_string(balance);
            char const *balance_char = balance_string.c_str();
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
            mvaddstr(37,187, balance_char);
            mvaddstr(40,170, "Bet amount: ");

            // setting up the buttons

            // start button
            mvaddstr(11, 16, "Start (s)");
            start_button = userwindow.create_buttons(10, 10);

            // hit button
            mvaddstr(16, 17, "Hit (2)");
            hit_button = userwindow.create_buttons(10, 15);

            // stand button
            mvaddstr(21, 16, "Stand (3)");
            stand_button = userwindow.create_buttons(10, 20);

            // double button
            mvaddstr(26, 16, "Double (4)");
            double_button = userwindow.create_buttons(10, 25);


            switch (input){
                case '1': // if the user ends the game
                    test = false;
                    stage = 2;
                    break;

                case 's': // if the user starts the game
                    // place holder for what will occur when start is pressed
                    betting_input = getch();
                    betting_window = userwindow.bet_window(10);

                    betamount_field[0] = new_field(1,1,26,180,0,0);
                    set_field_back(betamount_field[0], O_AUTOSKIP);

                    betamount_field[1] = NULL;

                    betting_form = new_form(betamount_field);
                    
                    post_form(betting_form);
                    mvaddch(26, 100, ' ');
                    printw("Please enter a bet amount: (press q when finished typing)");
                    betting_test = true;
                    while(betting_test == true){

                        while(betting_input == getch()){
                            switch(betting_input){
                                case '1':
                                    raw_betamount += '1';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '2':
                                    raw_betamount += '2';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '3':
                                    raw_betamount += '3';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '4':
                                    raw_betamount += '4';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '5':
                                    raw_betamount += '5';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '6':
                                    raw_betamount += '6';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '7':
                                    raw_betamount += '7';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '8':
                                    raw_betamount += '8';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case '9':
                                    raw_betamount += '9';
                                    form_driver(betting_form, betting_input);
                                    break;
                                case 'q':
                                    betting_test = false;
                                    break;

                                default:
                                    printw("Not a valid number type");
                                    break;
                            }
                        }
                    }
                    unpost_form(betting_form);
                    free_form(betting_form);

                    free_field(betamount_field[0]);
                    // free_field(betamount_field[1]);
                    userwindow.end_win(betting_window);

                    betamount = std::stoi(raw_betamount);
                    break;
                    

                case '2': // if the user presses hit
                    // place holder for what will occur when hit is pressed
                    break;

                case '3': // if the user presses stand
                    // place holder for what will occur when stand is pressed
                    break;

                case '4': // if the user presses double
                    // place holder for what will occur when double is pressed
                    break;
            }
            
        }
    }


    // closing the windows
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