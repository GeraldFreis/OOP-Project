testall: test

test: gameoutput
	./gameoutput

gameoutput: game.h game.cpp window.h window.cpp main-game.cpp
	g++ window.cpp game.cpp main-game.cpp -lncurses -lform -o gameoutput