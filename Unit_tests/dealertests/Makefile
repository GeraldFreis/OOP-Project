tests: outs

outs: programout
	./programout

programout: ../../blackjack.cpp
	g++ ../../blackjack.cpp ../../Game_files/bet.cpp ../../Game_files/window.cpp ../../Player_files/Person.cpp ../../Player_files/Human.cpp ../../Player_files/Dealer.cpp ../../Player_files/Safe_dealer.cpp ../../Player_files/Risky_dealer.cpp ../../Deck_files/deck.cpp ../../Deck_files/card.cpp testingsafe_dealer.cpp -lncurses -lform -o programout