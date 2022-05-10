testall: test

test: programout
	./programout

programout: card.h card.cpp deck.h deck.cpp Game_files/window.cpp Game_files/window.h Game_files/game.cpp Game_files/game.h Wallet/wallet.h Wallet/wallet.cpp main.cpp
	g++ card.cpp deck.cpp Game_files/window.cpp Game_files/game.cpp Wallet/wallet.cpp  main.cpp -lncurses -o programout
