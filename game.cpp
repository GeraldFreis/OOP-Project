

#include "game.h"
#define KEY_ESC 27


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
        initscr();
        clear();
        noecho();
        cbreak();    /* Line buffering disabled. pass on everything */
        // nodelay(stdscr, TRUE);
        keypad(stdscr, FALSE);
        key_input = getch();

<<<<<<< HEAD
        bool dealer_chosen = false;
        // printw("Would you like to vs a safe or risky dealer?");
        // printw("Press one for safe");
        // printw("Press two for risky");
        // refresh();
        // switch (key_input)
        //     {
        //     case 1:
        //         safe_dealer_chosen = true ;
        //         break;

        //     case KEY_ESC:
        //         test = false;
        //         stage=1;
        //         break;

        //     default:
        //         break;
        //     }
        




=======
        bool game_template_mode = true;
>>>>>>> b8a10e8fdc427d7e0e96bc36afede4ad0d602329
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
        

        bool game_has_begun = false;
        bool end_test = true;
        hit_counter = 0;

        bool user_busted = false;
        bool dealer_busted = false;
        bool user_win = false;
        bool dealer_win = false;
        bool draw = false;
        

        Blackjack blackjack(balance);

        // initialising the screen and box position

        printw("Use the keyboard entries on the buttons to play the game");
        refresh();



        Dealer *received_dealer; // dealer object that is returned by blackjack when a change to the cards is made
        Human *received_user; // dealer object that is returned by blackjack when a change to the cards is made
        std::vector<WINDOW *> dealt_cards;
        // game loop
        while(stage==1){

            if(game_template_mode == true){
                std::vector<WINDOW *> screen_object_arr = blackjack.game_template(); // initialising the blackjack's game template into a vector to be shown on screen

                // // setting each object on the screen to the created screen object
                dealer_card_1 =  screen_object_arr[0];
                dealer_card_2 =  screen_object_arr[1];
            }
        bool entered_stage = false;
        // string a = "hi";
        // string b = " ";
        // string c = " ";
        // string d = " ";

        while(stage==1){

            // if(entered_stage == false){
            //     std::vector<WINDOW *> screen_object_arr = blackjack.game_template();
            // }

            // if(entered_stage){
            //     string a = received_dealer->getCards()[0].getName().c_str();
            //     string b = received_dealer->getCards()[1].getName().c_str();
            //     string c = received_user->getCards()[0].getName().c_str();
            //     string d = received_user->getCards()[1].getName().c_str();
            // }
            entered_stage = true;
            //nodelay(stdscr, TRUE);
            std::vector<WINDOW *> screen_object_arr = blackjack.game_template();
            // initialising the blackjack start function into a vector
            

           

            

                player_card_1 =  screen_object_arr[2];
                player_card_2 =  screen_object_arr[3];
            
                // adding the buttons to the screen    
                start_button =  screen_object_arr[4];
                hit_button =  screen_object_arr[5];
                stand_button =  screen_object_arr[6];
                double_button =  screen_object_arr[7];
            }
            else {
                std::vector<WINDOW *> current_cards = blackjack.getarray();
                // setting each object on the screen to the created screen object
                dealer_card_1 =  current_cards[0];
                dealer_card_2 =  current_cards[1];

                player_card_1 =  current_cards[2];
                player_card_2 =  current_cards[3];

                std::vector<WINDOW *> screen_object_arr = blackjack.game_template(); // initialising the blackjack's game template into a vector to be shown on screen

                // adding the buttons to the screen    
                start_button =  screen_object_arr[4];
                hit_button =  screen_object_arr[5];
                stand_button =  screen_object_arr[6];
                double_button =  screen_object_arr[7];
            }

            // setting up the balance and betamount text
            string balance_string = std::to_string(balance);
            char const *balance_char = balance_string.c_str();

            string betamount_string = std::to_string(bet_amount);
            char const *betamount_char = betamount_string.c_str();


            received_dealer = blackjack.getdealer(); // holds the dealer and the user
            received_user = blackjack.gethuman();

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

            // setting up the buttons text
            // start button
            mvaddstr(11, 16, "Start (1)");
            // hit button
            mvaddstr(16, 17, "Hit (2)");
            // stand button
            mvaddstr(21, 16, "Stand (3)");
            // double button
            mvaddstr(26, 16, "Exit (ESC)");

        
            
            // showing the cards that were dealt on the screen as a string

            // // showing the dealer cards on screen
            mvaddch(15,60, ' ');
            printw(received_dealer->getCards()[0].getName().c_str());
            mvaddch(15,90, ' ');
            printw(received_dealer->getCards()[1].getName().c_str());
            mvaddch(15,120, ' ');
            printw(received_dealer->getCards()[2].getName().c_str());
            mvaddch(15,150, ' ');
            printw(received_dealer->getCards()[3].getName().c_str());
            mvaddch(15, 165, ' ');
            printw(received_dealer->getCards()[4].getName().c_str());
            refresh();
            // showing the user's cards on the screen
            mvaddch(45,60, ' ');
            printw(received_user->getCards()[0].getName().c_str());
            mvaddch(45,90, ' ');
            printw(received_user->getCards()[1].getName().c_str());
            mvaddch(45,120, ' ');
            printw(received_user->getCards()[2].getName().c_str());
            mvaddch(45,150, ' ');
            printw(received_user->getCards()[3].getName().c_str());
            mvaddch(45, 165, ' ');
            printw(received_user->getCards()[4].getName().c_str());

            int key_input = getch();

            switch (key_input)
            {
            case KEY_ESC:
                test = false;
                stage ++;
                break;

            case '1':
                if(game_has_begun == false){
                    dealt_cards = blackjack.start_game();
                    bet_amount = blackjack.get_bet_amount();

                    // setting the dealer cards and player cards to those dealt
                    dealer_card_1 = dealt_cards[0];
                    dealer_card_2 = dealt_cards[1];

                    player_card_1 = dealt_cards[2];
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
                    else {
                        player_card_4 = dealt_cards[9];
                        wrefresh(player_card_4);
                        refresh();
                    }
                    hit_counter += 1;
                    
                    while(blackjack.bust() == true && blackjack.winner() != "false alarm" && end_test == true) {
                        winner = window_tools.winner_window();
                        mvaddstr(25, 109, "The winner was: ");
                        printw(blackjack.winner().c_str());

                        mvaddstr(28, 104, "Totals of user vs dealer: ");
                        printw(to_string(blackjack.gethuman()->getCount()).c_str());

                        printw(" vs ");

                        printw(to_string(blackjack.getdealer()->getCount()).c_str());
                        mvaddstr(0,0, "Press 1 to exit window or 0 to play again");
                        
                        if(blackjack.winner() == "dealer"){
                            balance = balance - bet_amount;
                        }
                        else if(blackjack.winner() == "user"){
                            balance = balance + bet_amount;
                        }
                        else {
                            continue; // do nothing if it is a draw
                        }
                        nodelay(stdscr, FALSE);
                        key_input = getch();
                        switch (key_input)
                        {
                        case '1':
                            stage++;
                            test = false;
                            end_test = false;
                            break;

                        default:
                            end_test = false;
                            stage++;
                            break;
                        }
                        
                    if(blackjack.gethuman()->getCount() >21) {
                        stage++;
                        user_busted = true;
                        endwin();
                    }
                }
                break;

            case '3':
                if(game_has_begun) {
                    received_user->setMove("stand");

                    if(dealer_chosen){
                        if(blackjack.getdealer()->getCount() >14){
                            received_dealer->setMove("stand");
                        }
                        else{
                            received_dealer->setMove("hit");
                        }
                    }
                    else{
                        if(blackjack.getdealer()->getCount() >20){
                            received_dealer->setMove("stand");
                        }
                        else{
                            received_dealer->setMove("hit");
                        }
                    }


                    if(received_dealer->getMove() == "stand"){ // if the dealer chose to stand
                        // user_win = true;
                        stage++;
                        endwin();
                    }
                    else{
                        dealt_cards = blackjack.stand();
                        if(blackjack.getdealer()->getMove() == "hit"){ // if the dealer chose to hit
                            dealer_card_3 = dealt_cards[10];
                        }
                    }
                    
                }
                break;
            case '4':
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
            

            mvaddch(15,60, ' ');
            printw(received_dealer->getCards()[0].getName().c_str());
            mvaddch(15,90, ' ');
            printw(received_dealer->getCards()[1].getName().c_str());
            mvaddch(15,120, ' ');
            printw(received_dealer->getCards()[2].getName().c_str());
            mvaddch(15,150, ' ');
            printw(received_dealer->getCards()[3].getName().c_str());
            mvaddch(15, 165, ' ');
            printw(received_dealer->getCards()[4].getName().c_str());
            refresh();
            // showing the user's cards on the screen
            mvaddch(45,60, ' ');
            printw(received_user->getCards()[0].getName().c_str());
            mvaddch(45,90, ' ');
            printw(received_user->getCards()[1].getName().c_str());
            mvaddch(45,120, ' ');
            printw(received_user->getCards()[2].getName().c_str());
            mvaddch(45,150, ' ');
            printw(received_user->getCards()[3].getName().c_str());
            mvaddch(45, 165, ' ');
            printw(received_user->getCards()[4].getName().c_str());

        } // stage while loop ended
        // refresh();

        refresh();
        if(entered_stage){
            if(blackjack.getdealer()->getCount() >21) {
                dealer_busted = true;
            }
            else if(blackjack.gethuman()->getCount() >21) {
                user_busted = true;
            }
            else if(blackjack.gethuman()->getCount() > blackjack.getdealer()->getCount()) {
                user_win = true;
            }
            else if(blackjack.gethuman()->getCount() < blackjack.getdealer()->getCount()) {
                dealer_win = true;
            }
            else {
                draw = true;
            }
            


            //blanks screen that recieves true or false variables to decide who won
            if(user_busted || dealer_win){
                // give/take profit
                balance = balance - bet_amount;
                //print who won
                mvaddstr(30, 90, "The winner was: ");
                printw("Dealer");
                mvaddstr(33, 85, "Totals of user vs dealer: ");
                printw(to_string(blackjack.gethuman()->getCount()).c_str());
                printw(" vs ");
                printw(to_string(blackjack.getdealer()->getCount()).c_str());
                
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
            else if(dealer_busted || user_win){
                // give/take profit
                balance = balance + bet_amount;
                //print who won
                mvaddstr(30, 90, "The winner was: ");
                printw("User");
                mvaddstr(33, 85, "Totals of user vs dealer: ");
                printw(to_string(blackjack.gethuman()->getCount()).c_str());
                printw(" vs ");
                printw(to_string(blackjack.getdealer()->getCount()).c_str());
                
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
            else if(draw){
                //print who won
                mvaddstr(30, 90, "No winner. Bet returned.");
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


