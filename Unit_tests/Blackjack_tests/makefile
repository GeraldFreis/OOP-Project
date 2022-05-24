ll: testall
	
testall: output 
	./output

output:  wallet.o game_manager.o suits.o window.o bet.o person.o Human.o Safe_dealer.o Risky_dealer.o Dealer.o deck.o card.o blackjack.o testingblackjack.cpp
	g++ wallet.o game_manager.o suits.o window.o bet.o person.o Human.o Safe_dealer.o Risky_dealer.o Dealer.o deck.o card.o blackjack.o testingblackjack.cpp -lncurses -lform -o output

wallet.o: ../../Wallet/wallet.h ../../Wallet/wallet.cpp
	g++ -c ../../Wallet/wallet.cpp

game_manager.o:	../../Game_files/game_manager.cpp ../../Game_files/game_manager.h
	g++ -c ../../Game_files/game_manager.cpp -o game_manager.o

window.o:  ../../Game_files/window.h ../../Game_files/window.cpp 
	g++ -c ../../Game_files/window.cpp

suits.o: ../../Deck_files/suits.h ../../Deck_files/suits.cpp
	g++ -c ../../Deck_files/suits.cpp

bet.o: 	../../Game_files/bet.h ../../Game_files/bet.cpp  
	g++ -c ../../Game_files/bet.cpp 

person.o: ../../Player_files/person.cpp ../../Player_files/person.h
	g++ -c ../../Player_files/person.cpp 

Human.o: ../../Player_files/Human.cpp ../../Player_files/Human.h 
	g++ -c ../../Player_files/Human.cpp 

Safe_dealer.o:  ../../Player_files/Safe_dealer.h ../../Player_files/Safe_dealer.cpp 
	g++ -c ../../Player_files/Safe_dealer.cpp

Risky_dealer.o:  ../../Player_files/Risky_dealer.h ../../Player_files/Risky_dealer.cpp 
	g++ -c ../../Player_files/Risky_dealer.cpp

Dealer.o:  ../../Player_files/Dealer.cpp ../../Player_files/Dealer.h  
	g++ -c ../../Player_files/Dealer.cpp 

deck.o:  ../../Deck_files/deck.h ../../Deck_files/deck.cpp 
	g++ -c ../../Deck_files/deck.cpp

card.o: ../../Deck_files/card.cpp ../../Deck_files/card.h
	g++ -c ../../Deck_files/card.cpp 

blackjack.o: ../../blackjack.cpp ../../blackjack.h
	g++ -c ../../blackjack.cpp

clean: 
	rm -f output *.o
