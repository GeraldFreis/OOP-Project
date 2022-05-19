testall: tests

tests: programout.o
	./programout.o

programout.o: blackjack.o betandwindows.o dealersubs.o dealer.o person.o cards.o
	g++ testing_bust.cpp blackjack.o dealersubs.o -o programout.o


blackjack.o: ../blackjack.cpp  ../blackjack.h betandwindows.o
	g++ ../blackjack.cpp betandwindows.o -lncurses -lform -o blackjack.o


betandwindows.o: ../Game_files/bet.h ../Game_files/bet.cpp ../Game_files/window.h ../Game_files/window.cpp
	g++ ../Game_files/bet.cpp ../Game_files/window.cpp -lncurses -lform -o betandwindows.o


dealersubs.o: ../Player_files/Risky_dealer.h ../Player_files/Risky_dealer.cpp ../Player_files/Safe_dealer.h ../Player_files/Safe_dealer.cpp dealer.o person.o cards.o
	g++ ../Player_files/Risky_dealer.cpp ../Player_files/Safe_dealer.cpp dealer.o -o dealersubs.o

dealer.o: ../Player_files/Dealer.h ../Player_files/Dealer.cpp cards.o person.o
	g++ ../Player_files/Dealer.cpp person.o -o dealer.o


person.o: ../Player_files/Person.h ../Player_files/Person.cpp cards.o
	g++ ../Player_files/Person.cpp cards.o -o person


cards:	../Deck_files/deck.h ../Deck_files/deck.cpp ../Deck_files/card.h ../Deck_files/card.cpp
	g++ ../Deck_files/deck.cpp ../Deck_files/card.cpp -o -cards
