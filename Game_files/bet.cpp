#include "bet.h"

Bet::Bet(int _balance){
    balance = _balance;
    raw_bet_amount = "";
    bet_amount = 0;
};


bool Bet::isvalid_bet_amount(char betting_input){
    switch(betting_input){
            case '0':
                raw_bet_amount += '0';
                printw("%c", betting_input);
                return true;
            

            case '1':
                raw_bet_amount += '1';
                printw("%c", betting_input);
                return true;

            case '2':
                raw_bet_amount += '2';
                printw("%c", betting_input);
                return true;

            case '3':
                raw_bet_amount += '3';
                printw("%c", betting_input);
                return true;
                
            case '4':
                raw_bet_amount += '4';
                printw("%c", betting_input);
                return true;

            case '5':
                raw_bet_amount += '5';
                printw("%c", betting_input);
                return true;

            case '6':
                raw_bet_amount += '6';
                printw("%c", betting_input);
                return true;

            case '7':
                raw_bet_amount += '7';
                printw("%c", betting_input);
                return true;

            case '8':
                raw_bet_amount += '8';
                printw("%c", betting_input);
                return true;

            case '9':
                raw_bet_amount += '9';
                printw("%c", betting_input);
                return true;

            case 'q':
                return false;
                

            default:
                return true;
        }     
};

string Bet::bet_interface(){
    initscr();
    clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */

    WINDOW *betting_window = window_creation.bet_window(10);

    int betting_input;

    betting_input = getch();

    betamount_field[0] = new_field(1,1,30,130,0,0);
    set_field_back(betamount_field[0], O_AUTOSKIP);

    betamount_field[1] = NULL;

    betting_form = new_form(betamount_field);
    
    post_form(betting_form);

    
    mvaddch(26, 70, ' ');
    printw("Please enter a bet amount that is less than your balance: (press q when finished typing)"); 
    
    mvaddstr(30, 70, "Balance: ");
    string balance_string = std::to_string(balance); // converting the int to a const char
    char const *balance_char = balance_string.c_str();
    mvaddstr(30, 90, balance_char);

    bool betting_test = true;
    
    mvaddch(35, 100, ' '); // moves where the user enters the number

    while(betting_test == true){ // checking the user input
        betting_input = getch();
        if(isvalid_bet_amount(betting_input) != true){ // if the input was a 'q'
           betting_test = false;
        } 
    }
    
    unpost_form(betting_form);
    free_form(betting_form);

    free_field(betamount_field[0]);
    // free_field(betamount_field[1]);
    endwin();

    return raw_bet_amount;
};

void Bet::set_bet_amount(){
    while(bet_amount == 0){
        raw_bet_amount = bet_interface();

        if (raw_bet_amount != "") { // if the user entered a valid number
            bet_amount = std::stoi(raw_bet_amount);

            if(bet_amount > balance){ // if the bet amount is greater than the user's balance
                bet_amount = 0;
                raw_bet_amount = "";
            }

            else {
                return;
            }
            
        }

        else{
            bet_amount = 0;
        }

        
    }
};

int Bet::get_bet_amount(){
    return bet_amount;
}