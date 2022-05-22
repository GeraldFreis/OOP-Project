#include <iostream>
#include <ncurses.h>
#include "../../game.h"
#include "../../blackjack.h"

int main(){
    WINDOW *dealer_card_1; // dealer card 1 
    WINDOW *dealer_card_2;  // dealer card 2
    WINDOW *dealer_card_3; // dealer card 1
    WINDOW *dealer_card_4; // dealer card 2
    WINDOW *player_card_1; // player card 3
    WINDOW *player_card_2; // player card 4
    WINDOW *player_card_3; // player card 3
    WINDOW *player_card_4; // player card 4;

    // creating the buttons in the window
    WINDOW *hit_button;
    WINDOW *stand_button;
    WINDOW *double_button;
    WINDOW *start_button;

    initscr();
    clear();
    noecho();
    cbreak();
    Blackjack blackjack;

//    std::vector<WINDOW *> screen_object_arr =  blackjack.game_template();
    
    bool gamehasbegun = true;
    while(gamehasbegun){
        std::vector<WINDOW *> screen_object_arr =  blackjack.game_template();

        dealer_card_1 = screen_object_arr[0];
        dealer_card_2 = screen_object_arr[1];

        player_card_1 = screen_object_arr[2];
        player_card_2 = screen_object_arr[3];

        start_button = screen_object_arr[4];
        hit_button = screen_object_arr[5];
        stand_button = screen_object_arr[6];
        double_button = screen_object_arr[7];
        refresh();
        int key_input = getch();
        switch (key_input)
            {
            case '1':
                gamehasbegun = false;
                break;
            
            default:
                break;
            }
    }
    endwin();
}

