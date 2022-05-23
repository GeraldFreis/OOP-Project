#include "game.h"
#define KEY_ESC 27


Game::Game(){
    balance = 1000;
    bet_amount = 0;
    game_has_begun = false;
    hit_counter = 0;
    stand_counter = 0;

    Window window_tools;
    Blackjack blackjack(balance);
    Game_manager manager(balance);
}

Game::Game(int _balance){
    balance = _balance;
    bet_amount = 0;
    game_has_begun = false;
    hit_counter = 0;
    stand_counter = 0;
    Window window_tools;
    Blackjack blackjack(balance);
    Game_manager manager(balance);
}

Game::~Game(){
    cout << "Thanks for playing" << "\n";
}

void Game::mainscreen(){ // actual game loop
    bool test = true; // variable to control the game loop and end if the game is over
    bool dealer_chosen = false; // variable to control whether vs a risky or safe dealer 

    while(test){ //while loop to allow the user to play round after round 
        initscr();
        clear();
        noecho();
        cbreak();    /* Line buffering disabled. pass on everything */
        keypad(stdscr, FALSE);
         //list of variables reset for each round 
        bool game_has_begun = false;
        bool end_test = true;
        hit_counter = 0;
        stand_counter = 0;
        bool entered_stage = false;
        int stage = 0;
        // initialising the screen and box position
        printw("Use the keyboard entries on the buttons to play the game");
        refresh();
        //get input from user to continue 
        int key_input = getch();
        switch (key_input)
            {
            case KEY_ESC:
                test = false;
                break;

            case ' ':
                stage=1;

                break;
            default:
                break;
            }
        Blackjack blackjack(balance);
        std::vector<WINDOW *> screen_object_arr; //vector to hold the screen objects (Cards, buttons etc.)

        // while loop used to allow the player to make moves within the round 
        while(stage==1){ 
            entered_stage = true; // so the system knows it has entered the moves loop 
            // initialising the blackjack start function into a vector
            if(game_has_begun == false){
                screen_object_arr = blackjack.game_template();
            }
            else {
                screen_object_arr = blackjack.game_template(
                    blackjack.getdealer()->getCards()[0].getName(),
                    blackjack.getdealer()->getCards()[1].getName(),
                    blackjack.gethuman()->getCards()[0].getName(),
                    blackjack.gethuman()->getCards()[1].getName()
                );
            }
            std::vector<WINDOW *> dealt_cards; // vector to hold cards dealt at the beginning of the game

            // setting up the balance and betamount text
            string balance_string = std::to_string(balance);
            char const *balance_char = balance_string.c_str();

            string betamount_string = std::to_string(bet_amount);
            char const *betamount_char = betamount_string.c_str();

            // setting each object on the screen to the created screen object
            dealer_card_1 = screen_object_arr[0]; // dealers cards
            dealer_card_2 = screen_object_arr[1];
            player_card_1 = screen_object_arr[2]; // players cards
            player_card_2 = screen_object_arr[3];
            start_button = screen_object_arr[4]; // object buttons 
            hit_button = screen_object_arr[5];
            stand_button = screen_object_arr[6];
            double_button = screen_object_arr[7];

            // adding the text:
            if(dealer_chosen){
                mvaddstr(8,50,"Safe ");
                mvaddstr(8,55,"Dealer's cards: ");
            }
            else{
                mvaddstr(8,50,"Risky ");
                mvaddstr(8,56,"Dealer's cards: ");
            }
            mvaddstr(38,50,"Player's cards: ");
            mvaddstr(31,10, "Player balance: ");

            mvaddstr(31,28, balance_char);
            mvaddstr(33,10, "Bet amount: ");
            mvaddstr(33,28, betamount_char);

            // depending on users input a move is made 
            int key_input = getch();
            switch (key_input)
            {
            case KEY_ESC:
                test = false;
                stage ++;
                break;
            case '1':
                if(game_has_begun == false){
                    dealt_cards = blackjack.start_game(); // returns an array of cards to diplay on screen 
                    bet_amount = blackjack.get_bet_amount(); // switches to bet input window 
                    // setting the dealer cards and player cards to those dealt
                    dealer_card_1 = dealt_cards[0]; // dealers cards
                    dealer_card_2 = dealt_cards[1];
                    player_card_1 = dealt_cards[2]; // players cards
                    player_card_2 = dealt_cards[3];
                    printw("press any key to begin");
                }
                game_has_begun = true;
                break;
            case '2':
                if(game_has_begun && (hit_counter < 3)){ // if the user has pressed start game already
                    dealt_cards = blackjack.hit(hit_counter);
                    if(hit_counter == 0){
                        player_card_3 = dealt_cards[dealt_cards.size()-2];
                    }
                    else if(hit_counter == 1){
                        player_card_4 = dealt_cards[dealt_cards.size()-1];
                        // wrefresh(player_card_4);
                        // refresh();
                    }
                    else{
                        player_card_5 = dealt_cards[dealt_cards.size()-1];
                    }
                    hit_counter += 1;
                }
                break;
            case '3':
                if(game_has_begun) {
                    dealt_cards = blackjack.stand(stand_counter);
                    // if dealer has chosen to stand then ends the move loop 
                    if(blackjack.getdealer()->getMove() == "hit"){ // if the dealer chose to hit
                        dealer_card_3 = dealt_cards[dealt_cards.size()-1];
                    }
                    stand_counter += 1;
                }
                break;

            case '4':
                //switches the dealer by pressing the button once
                if(dealer_chosen){
                    dealer_chosen = false;
                }
                else{
                    dealer_chosen = true;
                }
                break;
            default:
                break;
            }

        refresh();
        if(blackjack.bust() == true){
            manager.setbalance(balance);
            manager.calcbalance(blackjack.get_bet_amount(), &blackjack);
            balance = manager.getbalance();
            
            if(manager.isdraw() == true){
                mvaddstr(30, 90, "No winner. Bet returned.");
            }
            else{   
                mvaddstr(30, 90, "The winner was: ");
                printw(blackjack.winner().c_str());
                mvaddstr(33, 85, "Totals of user vs dealer: ");
                printw(to_string(blackjack.gethuman()->getCount()).c_str());
                printw(" vs ");
                printw(to_string(blackjack.getdealer()->getCount()).c_str());
            } 
            nodelay(stdscr, FALSE);
            key_input = getch();
            switch (key_input)
            {
            case KEY_ESC:
                stage++;
                test = false;
                end_test = false;
                break;
            default:
                stage++;
                end_test = false;
                break;
            }
            endwin();
        }
        }
    }
    // closing the windows
    window_tools.end_win(dealer_card_1);
    window_tools.end_win(dealer_card_2);
    window_tools.end_win(player_card_1);
    window_tools.end_win(player_card_2);
    clear();
    endwin();

}

int Game::get_balance() {
    return balance;
}