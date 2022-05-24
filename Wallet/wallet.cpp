#include "wallet.h"

Wallet::Wallet(){ // default constructor
    currentbalance = 0;
    previousbalances = new int[100];
    filename = "../users_balances.txt";
    number_of_entries = 0;
}

Wallet::Wallet(string _filename){ // parameterized constructor
    currentbalance = 0;
    previousbalances = new int[100];
    filename = _filename;
    number_of_entries = 0;
}

// methods

// getting the current balance
int Wallet::getbalance(){
    return currentbalance;
}

// printing the current balance
void Wallet::printbalance(){
    cout << currentbalance << "\n";
}

// returning the previous balances
int *Wallet::getpreviousbalances(){
    return previousbalances;
}

// printing the previous balance (for testing purposes)
void Wallet::printpreviousbalances(){
    for(int i = 0; i < number_of_entries; i++){
        cout << previousbalances[i] << "\n";
    }
}

// setting the balance of the wallet
void Wallet::setbalance(int updated_balance){
    currentbalance = updated_balance; // updating the current balance

    // updating the previous balances to include this balance
    previousbalances[number_of_entries + 1] = updated_balance;
    number_of_entries += 1; // increasing the number of entries
}

// inherited function from deserializable (reads funds from file)
void Wallet::read() {
    // reading in the data
    std::ifstream file(filename);

    // initialising an array to capture the line values
    string temparray[100];
    int index_row = 0;

    while(file.good()){ // while we are still in the range of the file

        getline(file, (temparray[index_row]));
        index_row++;
    }
    // iterating over every line in the temporary array and transfering that value into the
    // data member previous balances for this class
    number_of_entries = 0;
    for(int i = 0; i < 100; i++){
        if(temparray[i] != ""){
            previousbalances[i] = stoi(temparray[i]);
            if(i > 0){
                number_of_entries += 1;
            }
        }
    }
    // setting the current balance
    currentbalance = previousbalances[number_of_entries];
    if(currentbalance == 0){ // if the user is broke
        currentbalance = 1000;
    }
}

// writing to the text file
void Wallet::write(){

    std::ofstream file(filename);

    // iterating over every balance in the previous balances and writing it to the file
    for(int i = 0; i <= number_of_entries; i++){
        file << previousbalances[i] << "\n";
    }
}

Wallet::~Wallet(){
    delete [] previousbalances;
    cout << "wallet closed" << "\n";
}