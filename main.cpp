#include <iostream>
#include <fstream>
#include "menu.h"
#include "BankAccountContainer.h"
using namespace std;

int main() {
    BankAccountContainer container;
    const string filename = "bank_data.bin";
    
    // Check if file exists before trying to load
    ifstream checkFile(filename);
    if (checkFile.good()) {
        checkFile.close();
        container.loadFromFile(filename);
    } else {
        cout << "No existing data file found. Starting with empty database." << endl;
    }
    
    Menu menu(container);
    menu.start();
    
    // Save data before exit
    container.saveToFile(filename);
    
    return 0;
}
