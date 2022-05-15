#include "blackjack.h"

Blackjack::Blackjack(): Bet(1000){
    balance = 1000;
    bet_amount = 0;
    betting = new Bet(1000); // default setting the Balance to 1000
    array.resize(13);
    
    // initialising the human and the dealer
    user = new Human();
    dealer = new Dealer();

    // intialising the deck
    srand ( time(NULL) );  
    initialised_deck.fillDeck();

};

Blackjack::Blackjack(int _balance): Bet (_balance){
    if(_balance > 0){balance = _balance;}
    else{balance = 0;}

    bet_amount = 0;
    betting = new Bet(balance);
    array.resize(13);

    // initialising the user and dealer
    user = new Human();
    dealer = new Dealer();

    // initialising the deck
    srand ( time(NULL) );  
    initialised_deck.fillDeck();
}

 // creates the template for the screen and returns a vector of the card templates
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

// starting the game protocol (gives the user and dealer 2 cards)
std::vector<WINDOW *> Blackjack::start_game(){ 
    
    // adding the cards to the player and dealer and retrieving the cards
    // initialising the deck

    // initialising the cards
    card *cards = new card[4];
    for(int i = 0; i < 4; i++) {cards[i] = initialised_deck.drawCard();
                                 initialised_deck.removeLastCard();}

    // adding the cards to the user and dealer
    user->addCardHuman(cards[0]);
    user->addCardHuman(cards[1]);

    dealer->addCardDealer(cards[2]);
    dealer->addCardDealer(cards[3]);
    
    // initialising the card windows
    
    WINDOW *dealer_card_1_window = windowtools.create_cards(10,70);
    WINDOW *dealer_card_2_window = windowtools.create_cards(10,100);

    // creating the players cards
    WINDOW *player_card_1_window = windowtools.create_cards(40, 70);
    WINDOW *player_card_2_window = windowtools.create_cards(40, 100);

    // erasing the pre-existing dealer and player cards
    array.erase(array.begin(), array.begin()+3);


    array[0] = dealer_card_1_window;
    array[1] = dealer_card_2_window;

    array[2] = player_card_1_window;
    array[3] = player_card_2_window;

    // getting the bet amount 
    betting->set_bet_amount();
    bet_amount = betting->get_bet_amount();

    return array;

}

// hit protocol (if user decides to hit)
std::vector<WINDOW *> Blackjack::hit(int hit_number){ // if the user chooses to hit

    // creating the two new cards for the player and then if the dealer decides to play displaying
    // returning their cards as well
    if(hit_number == 0){
        WINDOW *new_player_card_window = windowtools.create_cards(40, 130);
        
        array.push_back(new_player_card_window);

        // adding a card to the player
        card user_card = initialised_deck.drawCard();
        initialised_deck.removeLastCard();

        user->addCardHuman(user_card);
        user->setMove("hit");
        // calling the dealer place
    }

    else {
        // initialising the window for the player
        WINDOW *new_player_card_window = windowtools.create_cards(40, 160);
        array.push_back(new_player_card_window); // adding the window to the array

        // adding a card to the player
        card user_card = initialised_deck.drawCard();
        initialised_deck.removeLastCard();

        user->addCardHuman(user_card);
        user->setMove("hit");
    }

    // 

    return array;
}

// protocol if the user hits stand
std::vector<WINDOW *> Blackjack::stand(){
    user->setMove("stand");
    // user does nothing, dealer makes a decision based on their total
    return array;
};

// checks if the user or dealer is bust, if neither is bust then returns false, and if either is returns true
bool Blackjack::bust(){ 

    if(user->getCount() > 21 || dealer->getCount() > 21){ // if either the dealer or user are bust
        return true;
    }
    return false;
}

// function that returns a string of who won the game (can be called if either is bust or both stand)
string Blackjack::winner() {
    if(dealer->getCount() > 21) { // if the dealer is bust the user wins
        return "user";
    }

    else if (user->getCount() > 21) { // if the user is bust the dealer wins
        return "dealer";
    }

    else if (user->getMove() == "stand" && dealer->getMove() == "stand") { // if both the user and dealer stand
    
        if(user->getCount() > dealer->getCount()) { // if the user has a greater total (less than 21)
            return "user";
        }
        else if (user->getCount() == dealer->getCount()) { // if the user and dealer have the same total
            return "draw";
        }
        else { // if the dealer has a greater total than the user
            return "dealer"; 
        }
    }

    else { // if none of the conditions were met, this function should not have been called
        return "false alarm";
    }
}

int Blackjack::get_bet_amount(){
    return bet_amount;
}

Human *Blackjack::gethuman(){
    return user;
}

Dealer *Blackjack::getdealer(){
    return dealer;
}

Blackjack::~Blackjack(){
    delete betting;
    delete dealer;
    delete user;
}