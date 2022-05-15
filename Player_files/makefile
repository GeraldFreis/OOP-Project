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



all: testall

testall: playertest
	./playertest

playertest: card.h card.cpp deck.h deck.cpp Dealer.h Dealer.cpp Human.h Human.cpp person.h person.cpp  main-player.cpp
	g++ -Wall card.cpp deck.cpp Dealer.cpp Human.cpp person.cpp main-player.cpp -o playertest

clean: 
	rm -f playertest *.o