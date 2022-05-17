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

    // the winner window
    WINDOW *winner;
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

    // the winner window
    WINDOW *winner;
}

Game::~Game(){
    cout << "Thanks for playing" << "\n";
}



void Game::mainscreen(){ // actual game loop
    

    bool test = true; // variable to control the game loop and end if the game is over
    int stage = 1; // variable to control what stage we are in (i.e what screen to show)
    

    int key_input = 0;
    while(test){
        
        key_input = getch();

            switch (key_input)
            {
            case '1':
                test = false;
                break;

            case '0':
                stage=1;
                break;
            default:
                break;
            }

        bool game_has_begun = false;
        hit_counter = 0;
        initscr();
        clear();
        noecho();
        cbreak();    /* Line buffering disabled. pass on everything */

         Blackjack blackjack(balance);

        // initialising the screen and box position

        printw("Press the number 1 to exit, and any other key to move to the game window");
        refresh();



        Dealer *received_dealer; // dealer object that is returned by blackjack when a change to the cards is made
        Human *received_user; // dealer object that is returned by blackjack when a change to the cards is made





        while(stage==1){    
            keypad(stdscr, TRUE);
            
            // initialising the blackjack start function into a vector
            std::vector<WINDOW *> screen_object_arr = blackjack.game_template();

            std::vector<WINDOW *> dealt_cards; // vector to hold cards dealt at the beginning of the game

            // setting up the balance and betamount text
            string balance_string = std::to_string(balance);
            char const *balance_char = balance_string.c_str();

            string betamount_string = std::to_string(bet_amount);
            char const *betamount_char = betamount_string.c_str();


            received_dealer = blackjack.getdealer(); // holds the dealer and the user
            received_user = blackjack.gethuman();


            // setting each object on the screen to the created screen object
            dealer_card_1 = screen_object_arr[0];
            dealer_card_2 = screen_object_arr[1];

            player_card_1 = screen_object_arr[2];
            player_card_2 = screen_object_arr[3];

            start_button = screen_object_arr[4];
            hit_button = screen_object_arr[5];
            stand_button = screen_object_arr[6];
            double_button = screen_object_arr[7];
            refresh();

            // adding the text:
            mvaddstr(7,89,"Dealer's cards: ");
            mvaddstr(37,89,"Player's cards: ");

            mvaddstr(31,10, "Player balance: ");
            mvaddstr(31,28, balance_char);
            mvaddstr(33,10, "Bet amount: ");
            mvaddstr(33,28, betamount_char);

            // setting up the buttons text
            // start button
            mvaddstr(11, 16, "Start (s)");
            // hit button
            mvaddstr(16, 17, "Hit (2)");
            // stand button
            mvaddstr(21, 16, "Stand (3)");
            // double button
            mvaddstr(26, 16, "Double (4)");

        
            
            // showing the cards that were dealt on the screen as a string

            // // showing the dealer cards on screen
            mvaddch(15,80, ' ');
            printw(received_dealer->getCards()[0].getName().c_str());
            mvaddch(15,110, ' ');
            printw(received_dealer->getCards()[1].getName().c_str());
            mvaddch(15,130, ' ');
            printw(received_dealer->getCards()[2].getName().c_str());
            mvaddch(15,160, ' ');
            printw(received_dealer->getCards()[3].getName().c_str());
            mvaddch(15, 185, ' ');
            printw(received_dealer->getCards()[4].getName().c_str());
            refresh();
            // showing the user's cards on the screen
            mvaddch(45,80, ' ');
            printw(received_user->getCards()[0].getName().c_str());
            mvaddch(45,110, ' ');
            printw(received_user->getCards()[1].getName().c_str());
            mvaddch(45,130, ' ');
            printw(received_user->getCards()[2].getName().c_str());
            mvaddch(45,160, ' ');
            printw(received_user->getCards()[3].getName().c_str());
            mvaddch(45, 185, ' ');
            printw(received_user->getCards()[4].getName().c_str());
            refresh();

            int key_input = getch();

            switch (key_input)
            {
            case '1':
                test = false;
                break;

            case 's':
                if(game_has_begun == false){
                    dealt_cards = blackjack.start_game();
                    bet_amount = blackjack.get_bet_amount();

                    // setting the dealer cards and player cards to those dealt
                    dealer_card_1 = dealt_cards[0];
                    dealer_card_2 = dealt_cards[1];

                    player_card_1 = dealt_cards[2];
                    player_card_2 = dealt_cards[3];
                    printw("press any key to begin");
                    refresh();
                    //key_input=getch(); //does this help
                    
                    
                }
                game_has_begun = true;

            // case '2':
            //     if(game_has_begun){ // if the user has pressed start game already
            //         dealt_cards = blackjack.hit(hit_counter);

            //         if(hit_counter == 0){
            //             player_card_3 = dealt_cards[dealt_cards.size()-2];
            //             if(blackjack.getdealer()->getMove()=="hit") {
            //                 dealer_card_3 = dealt_cards[dealt_cards.size()-1];
            //                 continue;
            //             }
            //         }
            //         else {
            //             player_card_4 = dealt_cards[9];
            //             wrefresh(player_card_4);
            //             if(blackjack.getdealer()->getMove()=="hit"){
            //                 dealer_card_3 = dealt_cards[dealt_cards.size()-1];
            //                 continue;
            //             }
            //         }
            //         hit_counter += 1;
            //         refresh();
            //         if(blackjack.bust() == true && blackjack.winner() != "false alarm") {
            //             winner = window_tools.winner_window();
            //             mvaddstr(25, 109, "The winner was: ");
            //             printw(blackjack.winner().c_str());

            //             mvaddstr(28, 104, "Totals of user vs dealer: ");
            //             printw(to_string(blackjack.gethuman()->getCount()).c_str());

            //             printw(" vs ");

            //             printw(to_string(blackjack.getdealer()->getCount()).c_str());
            //             mvaddstr(0,0, "Press 1 to exit window or 0 to play again");

            //             refresh();
            //         }


            //     }
            //     break;

            // case '3':
            //     if(game_has_begun) {
            //         dealt_cards = blackjack.stand();
            //         dealer_card_3 = dealt_cards[10];
            //         refresh();

            //         if(blackjack.bust() == true && blackjack.winner() != "false alarm") {
            //             winner = window_tools.winner_window();
            //             mvaddstr(25, 109, "The winner was: ");
            //             printw(blackjack.winner().c_str());

            //             mvaddstr(28, 104, "Totals of user vs dealer: ");
            //             printw(to_string(blackjack.gethuman()->getCount()).c_str());

            //             printw(" vs ");

            //             printw(to_string(blackjack.getdealer()->getCount()).c_str());
            //             mvaddstr(0,0, "Press 1 to exit window or 0 to play again");

            //             refresh();
            //         }

                    
            //     }
            //     break;


            default:
                break;
            }
            refresh();




        
            key_input = getch();

            switch (key_input)
            {
            case '1':
                test = false;
                break;

            case '2':
                if(game_has_begun && (hit_counter < 3)){ // if the user has pressed start game already
                    dealt_cards = blackjack.hit(hit_counter);

                    if(hit_counter == 0){
                        player_card_3 = dealt_cards[dealt_cards.size()-2];
                        if(blackjack.getdealer()->getMove()=="hit") {
                            dealer_card_3 = dealt_cards[dealt_cards.size()-1];
                            continue;
                        }
                    }
                    else {
                        player_card_4 = dealt_cards[9];
                        wrefresh(player_card_4);
                        if(blackjack.getdealer()->getMove()=="hit"){
                            dealer_card_3 = dealt_cards[dealt_cards.size()-1];
                            continue;
                        }
                    }
                    hit_counter += 1;
                    refresh();
                    if(blackjack.bust() == true && blackjack.winner() != "false alarm") {
                        winner = window_tools.winner_window();
                        mvaddstr(25, 109, "The winner was: ");
                        printw(blackjack.winner().c_str());

                        mvaddstr(28, 104, "Totals of user vs dealer: ");
                        printw(to_string(blackjack.gethuman()->getCount()).c_str());

                        printw(" vs ");

                        printw(to_string(blackjack.getdealer()->getCount()).c_str());
                        mvaddstr(0,0, "Press 1 to exit window or 0 to play again");

                        key_input = getch();
                        switch (key_input)
                        {
                        case '1':
                            stage++;
                            test = false;
                            break;
                        default:
                            stage++;
                        }
                        refresh();
                    }


                }
                break;

            case '3':
                if(game_has_begun) {
                    dealt_cards = blackjack.stand();
                    dealer_card_3 = dealt_cards[10];
                    refresh();

                    if(blackjack.bust() == true && blackjack.winner() != "false alarm") {
                        winner = window_tools.winner_window();
                        mvaddstr(25, 109, "The winner was: ");
                        printw(blackjack.winner().c_str());

                        mvaddstr(28, 104, "Totals of user vs dealer: ");
                        printw(to_string(blackjack.gethuman()->getCount()).c_str());

                        printw(" vs ");

                        printw(to_string(blackjack.getdealer()->getCount()).c_str());
                        mvaddstr(0,0, "Press 1 to exit window or 0 to play again");
                        
                        key_input = getch();
                        switch (key_input)
                        {
                        case '1':
                            stage++;
                            test = false;
                            break;
                        default:
                            stage++;
                        }
                        refresh();
                    }

                    
                }
                break;


            default:
                break;
            }

            // ////////////////profit 
            // if(user == winner ){
            //     profit = bet*2; 
            // }
            // else if(stand == true){
            //     profit = bet;
            // }
            // else
            //     profit = 0;
            // }
            // wallet = wallet + profit;
            // bet = 0;
            // }
            // take bet away from balance at start 










            
        }
        
        



       // closing the windows
        window_tools.end_win(dealer_card_1);
        window_tools.end_win(dealer_card_2);
        window_tools.end_win(player_card_1);
        window_tools.end_win(player_card_2);
        clear();
        endwin();
    }
    
}