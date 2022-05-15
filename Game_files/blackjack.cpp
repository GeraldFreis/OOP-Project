#include "blackjack.h"

Blackjack::Blackjack(): Bet(1000){
    balance = 1000;
    bet_amount = 0;
    betting = new Bet(1000); // default setting the Balance to 1000
    array.resize(13);
};

Blackjack::Blackjack(int _balance): Bet (_balance){
    if(_balance > 0){balance = _balance;}
    else{balance = 0;}

    bet_amount = 0;
    betting = new Bet(balance);
    array.resize(13);
}

std::vector<WINDOW *> Blackjack::game_template(){ // creates the template for the screen 

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

    // adding each window to the window array that will be returned
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

std::vector<WINDOW *> Blackjack::start_game(){ // starting the game protocol (gives the user and dealer 2 cards)
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
    betting->set_bet_amount();
    bet_amount = betting->get_bet_amount();

    return array;

}


std::vector<WINDOW *> Blackjack::hit(int hit_number){ // if the user chooses to hit

    // creating the two new cards for the player and then if the dealer decides to play displaying
    // returning their cards as well
    if(hit_number == 0){
        WINDOW *new_player_card = windowtools.create_cards(40, 130);
        
        array.push_back(new_player_card);

        // calling the dealer place
    }

    else {
        WINDOW *new_player_card = windowtools.create_cards(40, 160);
        array.push_back(new_player_card);
    }

    // 

    return array;
}

std::vector<WINDOW *> Blackjack::stand(){
    // user does nothing, dealer makes a decision based on their total
    return array;
};

bool Blackjack::bust(){ // checks if the user or dealer is bust, if neither is bust then returns false, and if either is returns true
    return false;
}

int Blackjack::get_bet_amount(){
    return bet_amount;
}

Blackjack::~Blackjack(){
    delete betting;
}