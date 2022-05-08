#include <iostream>
#include <ncurses.h>

WINDOW *create_win(int height, int width, int xpoint, int ypoint);
void end_win(WINDOW *usingwin);
WINDOW *create_cards(int xpoint, int ypoint);

int main(){
    WINDOW *mainwindow;
    int height, width, xpoint, ypoint;

    initscr();
    clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */

    // initialising the screen and box position
    height = 40;
    width = 120;
    xpoint = 10;
    ypoint = 10;

    printw("Press the number 1 to exit");
    refresh();
    mainwindow = create_win(height, width, xpoint, ypoint);

    // creating the cards in the window
    WINDOW *card_1;
    WINDOW *card_2;
                
    WINDOW *card_3;
    WINDOW *card_4;

    bool test = true;
    int stage = 1;
    keypad(stdscr, TRUE);

    // game loop
    while (test){
        while(stage == 1){
            int input = getch();
            if (input == '2'){
                end_win(mainwindow);
                stage = 2; 
                break;
            }
            else if(input == '1'){
                test = false;
                break;
            }
            else {
                continue;
            }
        }
        while(stage == 2){
            int input = getch();

            card_1 = create_cards(10,70);
            card_2 = create_cards(40,70);
        
            card_3 = create_cards(10,110);
            card_4 = create_cards(40,110);

            // game loop
            
            if(input == '1'){
                test = false;
                break;
            }
            
        }
    }
    
    endwin();
    return 0;
}

WINDOW *create_win(int height, int width, int xpoint, int ypoint){
    WINDOW *this_win;

    this_win = newwin(height, width, xpoint, ypoint);
    box(this_win, 0, 0);

    wrefresh(this_win);

    return this_win;
}

WINDOW *create_cards(int xpoint, int ypoint){
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(20,30, xpoint,ypoint);
    box(card, 0, 0);

    wrefresh(card);
    return card;
}

void end_win(WINDOW *local_win){
    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
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
	wrefresh(local_win);
	// delwin(local_win);
}