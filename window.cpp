#include "window.h"

void Window::end_win(WINDOW *usingwin){
    wborder(usingwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(usingwin);
}
WINDOW *Window::create_cards(int xpoint, int ypoint){
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);

    wrefresh(card);
    return card;
}