#include "blackjack.h"

Blackjack::Blackjack(){
    balance = 1000;
    bet_amount = 0;
    Bet betting(1000); // default setting the Balance to 1000
    array.resize(13);
};

Blackjack::Blackjack(int _balance){
    balance = _balance;
    bet_amount = 0;
    Bet betting(balance);
    array.resize(13);
}

std::vector<WINDOW *> Blackjack::game_template(){

    // creating the dealers cards
    WINDOW *dealer_card_1 = windowtools.create_cards(10, 70);
    WINDOW *dealer_card_2 = windowtools.create_cards(10, 100);

    // creating the players cards
    WINDOW *player_card_1 = windowtools.create_cards(40, 70);
    WINDOW *player_card_2 = windowtools.create_cards(40, 100);

    // creating the buttons
    // start button
    WINDOW *start_button = windowtools.create_buttons(10, 10);

    // hit button
    WINDOW *hit_button = windowtools.create_buttons(10, 15);

    // stand button
    WINDOW *stand_button = windowtools.create_buttons(10, 20);

    // double button
    WINDOW *double_button = windowtools.create_buttons(10, 25);

    // adding each window to the window array
    array.push_back(dealer_card_1);
    array.push_back(dealer_card_2);
    array.push_back(player_card_1);
    array.push_back(player_card_2);
    array.push_back(start_button);
    array.push_back(hit_button);
    array.push_back(stand_button);
    array.push_back(double_button);

    return array;
}

std::vector<WINDOW *> Blackjack::start_game(){
    WINDOW *dealer_card_1 = windowtools.create_cards(10,70);
    WINDOW *dealer_card_2 = windowtools.create_cards(10,100);

    // creating the players cards
    WINDOW *player_card_1 = windowtools.create_cards(40, 70);
    WINDOW *player_card_2 = windowtools.create_cards(40, 100);

    // erasing the pre-existing dealer and player cards
    array.erase(array.begin(), array.begin()+3);


    array[0] = dealer_card_1;
    array[1] = dealer_card_2;

    array[2] = player_card_1;
    array[3] = player_card_2;

    // getting the bet amount 
    betting.set_bet_amount();
    bet_amount = betting.get_bet_amount();

    return array;

}


std::vector<WINDOW *> Blackjack::hit(){

    // creating the two new cards for the player and then if the dealer decides to play displaying
    // returning their cards as well

    WINDOW *new_player_card = windowtools.create_cards(40, 130);
    
    array.push_back(new_player_card);

    // calling the dealer place

    return array;
}

std::vector<WINDOW *> Blackjack::stand(){
    return array;
};

int Blackjack::get_bet_amount(){
    return bet_amount;
}