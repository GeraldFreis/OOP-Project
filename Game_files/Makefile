testall: tests

tests: programoutput
	./programoutput

programoutput: game.h window.h bet.h blackjack.h game.cpp window.cpp bet.cpp blackjack.cpp game_testing.cpp
	g++ game.cpp window.cpp bet.cpp blackjack.cpp game_testing.cpp -lncurses -lform -o programoutput