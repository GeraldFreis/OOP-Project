all: testall

testall: walletoutput
	./walletoutput

walletoutput: wallet.cpp main-wallet.cpp
	g++ wallet.cpp main-wallet.cpp -o walletoutput
