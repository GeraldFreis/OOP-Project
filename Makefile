maincppoutput: output
	./output

output: blackjack.cpp blackjack.h game.cpp game.h Game_files/bet.h Game_files/bet.cpp Game_files/window.h Game_files/window.cpp Player_files/card.cpp Player_files/card.h Player_files/deck.h Player_files/deck.cpp Player_files/Dealer.cpp Player_files/Dealer.h Player_files/Human.cpp Player_files/Human.h Player_files/person.cpp Player_files/person.h Wallet/wallet.h Wallet/wallet.cpp main.cpp
	g++ blackjack.cpp game.cpp Game_files/bet.cpp Game_files/window.cpp Player_files/card.cpp Player_files/deck.cpp Player_files/Dealer.cpp Player_files/Human.cpp Player_files/person.cpp Wallet/wallet.cpp main.cpp -lncurses -lform -o output