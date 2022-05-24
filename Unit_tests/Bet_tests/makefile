testall: tests

tests: programout
	./programout

programout: bet.o window.o suits.o deck.o card.o
	g++ bet.o window.o suits.o deck.o card.o bet_testing.cpp -lncurses -lform -o programout

bet.o: ../../Game_files/bet.cpp ../../Game_files/bet.h
	g++ -c ../../Game_files/bet.cpp

window.o: ../../Game_files/window.h ../../Game_files/window.cpp
	g++ -c ../../Game_files/window.cpp

suits.o: ../../Deck_files/suits.h ../../Deck_files/suits.cpp	
	g++ -c ../../Deck_files/suits.cpp

deck.o: ../../Deck_files/deck.cpp ../../Deck_files/deck.h
	g++ -c ../../Deck_files/deck.cpp

card.o: ../../Deck_files/card.h ../../Deck_files/card.cpp
	g++ -c ../../Deck_files/card.cpp

