#include "window.h"

void Window::end_win(WINDOW *usingwin){ // closing the window
    wborder(usingwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(usingwin);

}
WINDOW *Window::create_cards(int xpoint, int ypoint){ // creating the cards
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);

    wrefresh(card);
    return card;
}