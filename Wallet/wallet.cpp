#include "wallet.h"

Wallet::Wallet(){
    currentbalance = 0;
    previousbalances = new int[20];
    filename = "users_balances.txt";
    number_of_entries = 0;
}

Wallet::Wallet(string _filename){
    currentbalance = 0;
    previousbalances = new int[20];
    filename = _filename;
    number_of_entries = 0;
}

// methods
int Wallet::getbalance(){
    return currentbalance;
}
void Wallet::printbalance(){
    cout << currentbalance << "\n";
}
void Wallet::retreivebalance(){
    // reading in the data
    std::ifstream file(filename);
    std::string row;

    // initialising an array to capture the line values
    string temparray[40];
    int index_row = 0;

    while(file.good()){ // while we are still in the range of the file

        getline(file, (temparray[index_row]));
        
        index_row++;
    }
    // iterating over every line in the temporary array and transfering that value into the
    // data member previous balances for this class
    for(int i = 0; i < 20; i++){
        if(temparray[i] != ""){
            previousbalances[i] = stoi(temparray[i]);
            number_of_entries += 1;
        }
    }
    
    currentbalance = previousbalances[number_of_entries];
}
int *Wallet::getpreviousbalances(){
    return previousbalances;
}
void Wallet::printpreviousbalances(){
    for(int i = 0; i < number_of_entries; i++){
        cout << previousbalances[i] << "\n";
    }
}
void Wallet::setbalance(int updated_balance){
    
}