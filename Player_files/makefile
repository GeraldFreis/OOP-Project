# all: testall

# testall: playertest
# 	./playertest

# playertest: person.o main-player.cpp
# 	g++ -Wall person.o main-player.cpp -o playertest

# person.o: deck.o Dealer.h Dealer.cpp Human.h Human.cpp person.h person.cpp 
# 	g++ -Wall deck.o Dealer.cpp Human.cpp person.cpp -o person.o 

# deck.o: deck.h deck.cpp
# 	g++ -Wall card.o deck.cpp

# card.o: card.h card.cpp 
# 	g++ -Wall -c card.cpp

# clean: 
# 	rm -f playertest *.o
#include "../Deck_files/deck.h"
#include "../Deck_files/card.h"


all: testall

testall: playertest
	./playertest

playertest: ../Deck_files/card.h ../Deck_files/card.cpp ../Deck_files/deck.h ../Deck_files/deck.cpp Safe_dealer.h Safe_dealer.cpp Dealer.h Dealer.cpp Human.h Human.cpp person.h person.cpp  main-player.cpp
	g++ -Wall ../Deck_files/card.cpp ../Deck_files/deck.cpp Safe_dealer.cpp Dealer.cpp Human.cpp person.cpp main-player.cpp -o playertest

clean: 
	rm -f playertest *.o