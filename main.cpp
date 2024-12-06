#include <iostream>
#include <fstream>
#include "menu.h"
#include "BankAccountContainer.h"
using namespace std;

/**
 * @brief Main entry point for the banking application
 * @return Exit status code
 * 
 * @details Initializes the banking system, loads existing data if available,
 * runs the main menu interface, and saves data before exit.
 */
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
    
    // Create and start menu system
    Menu menu(container);
    menu.start();
    
    // Save data before exit
    container.saveToFile(filename);
    
    return 0;
}
