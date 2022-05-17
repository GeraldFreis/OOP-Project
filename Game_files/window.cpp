#include "window.h"

Window::Window(){
    colour_grey_array = new int[3];
    colour_grey_array[0] = 128;
    colour_grey_array[1] = 128;
    colour_grey_array[2] = 128;
}

// closing the window
void Window::end_win(WINDOW *usingwin){
    wborder(usingwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(usingwin);
    werase(usingwin);
};

// creating the cards
WINDOW *Window::create_cards(int xpoint, int ypoint){ 
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);

    wrefresh(card);
    return card;
};
// creating the cards
WINDOW *Window::create_cards(int xpoint, int ypoint, string cardname){ 
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);

    wrefresh(card);
    return card;
};

// creating the buttons in the window
WINDOW *Window::create_buttons(int xpoint, int ypoint){
    WINDOW *button; // initialising the buttons

    // this button
    button = newwin(3,20, ypoint, xpoint);
    box(button, 0, 0);

    // attroff(COLOR_PAIR(1)); // turning the colour off
    
    wrefresh(button);
    return button;
};


// window that prompts the user to enter a bet amount, and lets them enter the bet amount
WINDOW *Window::bet_window(int size){ 
    WINDOW *betting_window;

    betting_window = newwin(200,200,0,0);
    wrefresh(betting_window);

    return betting_window;
};

// winner window to show the user if a party has won
WINDOW *Window::winner_window(){
    WINDOW *winner_win;

    winner_win = newwin(200, 200, 0, 0);
    // wrefresh(winner_win);

    return winner_win;
}

Window::~Window(){
    delete colour_grey_array;
}