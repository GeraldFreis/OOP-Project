#include "game.h"


Game::Game(){
    balance = 1000;
    bet_amount = 0;
    game_has_begun = false;
    hit_counter = 0;

    WINDOW *dealer_card_1; // dealer card 1 
    WINDOW *dealer_card_2;  // dealer card 2
    WINDOW *dealer_card_3; // dealer card 1
    WINDOW *dealer_card_4; // dealer card 2
    WINDOW *player_card_1; // player card 3
    WINDOW *player_card_2; // player card 4
    WINDOW *player_card_3; // player card 3
    WINDOW *player_card_4; // player card 4;

    Window window_tools;
    Blackjack blackjack(balance);

    // creating the buttons in the window
    WINDOW *hit_button;
    WINDOW *stand_button;
    WINDOW *double_button;
    WINDOW *start_button;
}

Game::Game(int _balance){
    balance = _balance;
    bet_amount = 0;
    game_has_begun = false;
    hit_counter = 0;

    WINDOW *dealer_card_1; // dealer card 1 
    WINDOW *dealer_card_2;  // dealer card 2
    WINDOW *dealer_card_3; // dealer card 1
    WINDOW *dealer_card_4; // dealer card 2
    WINDOW *player_card_1; // player card 3
    WINDOW *player_card_2; // player card 4
    WINDOW *player_card_3; // player card 3
    WINDOW *player_card_4; // player card 4;

    Window window_tools;
    Blackjack blackjack(balance);

    // creating the buttons in the window
    WINDOW *hit_button;
    WINDOW *stand_button;
    WINDOW *double_button;
    WINDOW *start_button;
}

void Game::mainscreen(){ // actual game loop
    initscr();
    clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */

    // initialising the screen and box position

    printw("Press the number 1 to exit, and any other key to move to the game window");
    refresh();

    bool test = true; // variable to control the game loop and end if the game is over
    int stage = 1; // variable to control what stage we are in (i.e what screen to show)

    Dealer *received_dealer; // dealer object that is returned by blackjack when a change to the cards is made
    Human *received_user; // dealer object that is returned by blackjack when a change to the cards is made

    while (test) { // the game loop
    
        while(stage == 1) {

            keypad(stdscr, TRUE);
            int key_input = getch();

            // initialising the blackjack start function into a vector
            std::vector<WINDOW *> screen_object_arr = blackjack.game_template();

            // setting each object on the screen to the created screen object
            dealer_card_1 = screen_object_arr[0];
            dealer_card_2 = screen_object_arr[1];

            player_card_1 = screen_object_arr[2];
            player_card_2 = screen_object_arr[3];

            start_button = screen_object_arr[4];
            hit_button = screen_object_arr[5];
            stand_button = screen_object_arr[6];
            double_button = screen_object_arr[7];

            // refresh();

            // adding the text:
            mvaddstr(7,89,"Dealer's cards: ");
            mvaddstr(37,89,"Player's cards: ");
            
            // setting up the balance and betamount text
            string balance_string = std::to_string(balance);
            char const *balance_char = balance_string.c_str();

            string betamount_string = std::to_string(bet_amount);
            char const *betamount_char = betamount_string.c_str();

            mvaddstr(27,170, "Player balance: ");
            mvaddstr(27,187, balance_char);
            mvaddstr(30,170, "Bet amount: ");
            mvaddstr(30,187, betamount_char);

            // setting up the buttons text
            
            // start button
            mvaddstr(11, 16, "Start (s)");

            // hit button
            mvaddstr(16, 17, "Hit (2)");

            // stand button
            mvaddstr(21, 16, "Stand (3)");

            // double button
            mvaddstr(26, 16, "Double (4)");

            std::vector<WINDOW *> dealt_cards; // vector to hold cards dealt at the beginning of the game

            // showing the cards that were dealt on the screen as a string
            received_dealer = blackjack.getdealer();
            received_user = blackjack.gethuman();

            // // showing the dealer cards on screen
            mvaddch(15,85, ' ');
            printw(received_dealer->getCards()[0].getName().c_str());
            mvaddch(15,105, ' ');
            printw(received_dealer->getCards()[1].getName().c_str());
            mvaddch(15,125, ' ');
            printw(received_dealer->getCards()[2].getName().c_str());
            mvaddch(15,145, ' ');
            printw(received_dealer->getCards()[3].getName().c_str());
            mvaddch(15, 165, ' ');
            printw(received_dealer->getCards()[4].getName().c_str());

            // showing the user's cards on the screen
            mvaddch(45,80, ' ');
            printw(received_user->getCards()[0].getName().c_str());
            mvaddch(45,110, ' ');
            printw(received_user->getCards()[1].getName().c_str());
            mvaddch(45,135, ' ');
            printw(received_user->getCards()[2].getName().c_str());
            mvaddch(45,160, ' ');
            printw(received_user->getCards()[3].getName().c_str());
            mvaddch(45, 185, ' ');
            printw(received_user->getCards()[4].getName().c_str());
            refresh();

            switch(key_input) { // testing the user input
                case '1': // if the user wants to exit the game
                    test = false;
                    stage = 0;
                    break;

                case 's': // if the user wants to start the game
                    dealt_cards = blackjack.start_game();
                    bet_amount = blackjack.get_bet_amount();

                    // setting the dealer cards and player cards to those dealt
                    dealer_card_1 = dealt_cards[0];
                    dealer_card_2 = dealt_cards[1];

                    player_card_1 = dealt_cards[2];
                    player_card_2 = dealt_cards[3];
                    printw("press any key to begin");
                    refresh();
                    
                    game_has_begun = true;
                    break;
                
                case '2': // if the user wants to hit
                    if(game_has_begun){ // if the user has pressed start game already
                        dealt_cards = blackjack.hit(hit_counter);
                        player_card_3 = dealt_cards[8];
                        player_card_4 = dealt_cards[9];
                        hit_counter += 1;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    // closing the windows
    window_tools.end_win(dealer_card_1);
    window_tools.end_win(dealer_card_2);
    window_tools.end_win(player_card_1);
    window_tools.end_win(player_card_2);

    endwin();
    return;
}

Game::~Game(){
    cout << "Thanks for playing" << "\n";
};