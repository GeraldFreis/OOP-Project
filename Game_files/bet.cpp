#include "bet.h"
#include <string>
#define KEY_DEL 31


Bet::Bet(int _balance){
    if(balance < 0){balance = 0;}
    else {
        balance = _balance;
    }
    raw_bet_amount = "";
    // copy = "";
    bet_amount = 0;
};


bool Bet::isvalid_bet_amount(char betting_input) { // checks if the entered character is a number, and if so adds it to raw_bet_amount
    switch(betting_input) {

        case '0': // if the user enters a 0
            raw_bet_amount += '0';
            printw("%c", betting_input);
            return true;
        

        case '1': // if the user enters a 1
            raw_bet_amount += '1';
            printw("%c", betting_input);
            return true;

        case '2': // if the user enters a 2
            raw_bet_amount += '2';
            printw("%c", betting_input);
            return true;

        case '3': // if the user enters a 3
            raw_bet_amount += '3';
            printw("%c", betting_input);
            return true;
            
        case '4': // if the user enters a 4
            raw_bet_amount += '4';
            printw("%c", betting_input);
            return true;

        case '5': // if the user enters a 5
            raw_bet_amount += '5';
            printw("%c", betting_input);
            return true;

        case '6': // if the user enters a 6
            raw_bet_amount += '6';
            printw("%c", betting_input);
            return true;

        case '7': // if the user enters a 7
            raw_bet_amount += '7';
            printw("%c", betting_input);
            return true;

        case '8': // if the user enters a 8
            raw_bet_amount += '8';
            printw("%c", betting_input);
            return true;

        case '9': // if the user enters a 9
            raw_bet_amount += '9';
            printw("%c", betting_input);
            return true;

        // case KEY_DEL:
        //     // for(int i=0; raw_bet_amount.length()-1; i++){
        //     //     copy[i] = raw_bet_amount[i];
        //     // }
        //     // raw_bet_amount = copy;
        //     raw_bet_amount += '9';
        //     printw("%c", betting_input);
        //     return true;

        case 'q': // if the user enters a q (they want to quit the screen)
            return false;

        default: // if the user entered a key which was not a number, just ignore
            return true;
    }     
};

string Bet::bet_interface(){ // creates the window and prompts the user for the bet amount
    initscr();
    clear();
	noecho();
	cbreak();

    // initialising the window
    WINDOW *betting_window = window_creation.bet_window(10);

    int betting_input;

    betting_input = getch();

    // initialising the input fields
    betamount_field[0] = new_field(1,1,30,130,0,0);
    set_field_back(betamount_field[0], O_AUTOSKIP);

    betamount_field[1] = NULL;

    betting_form = new_form(betamount_field);
    
    post_form(betting_form);

    // initialising the text
    mvaddch(26, 70, ' ');
    printw("Please enter a bet amount that is less than your balance: (press q when finished typing)"); 
    
    mvaddstr(30, 70, "Balance: ");
    string balance_string = std::to_string(balance); // converting the int to a const char
    char const *balance_char = balance_string.c_str();
    mvaddstr(30, 90, balance_char);

    bool betting_test = true;
    
    mvaddch(35, 100, ' '); // moves where the user enters the number
    // checking user input
    while(betting_test == true){
        betting_input = getch();
        if(isvalid_bet_amount(betting_input) != true){ // if the input was a 'q'
            betting_test = false;
            endwin();
            // clearing the window
            unpost_form(betting_form);
            free_form(betting_form);
            free_field(betamount_field[0]);
            window_creation.end_win(betting_window);
            
            endwin();
        } 
    }
    

    return raw_bet_amount;
};

void Bet::set_bet_amount(){ // uses bet_interface to find the bet amount and checks if it is less than the balance
    while(bet_amount == 0) {
        raw_bet_amount = bet_interface(); // opening the interface to ask for the bet amount

        if (raw_bet_amount != "") { // if the user entered a valid number
            bet_amount = std::stoi(raw_bet_amount);

            if(bet_amount > balance){ // if the bet amount is greater than the user's balance
                bet_amount = 0;
                raw_bet_amount = "";
            }

            else { // if the bet_amount is less than the average
                return;
            }
            
        }

        else {
            bet_amount = 0; // resetting the bet amount if the user did not enter anything
        }
    }
};

int Bet::get_bet_amount(){ // returns bet amount 
    return bet_amount;
}

int Bet::get_balance(){
    return balance;
}