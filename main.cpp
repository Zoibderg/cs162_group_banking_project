#include <iostream>
#include "menu.h" // Includes the Menu class for managing the UI

using namespace std;

/**
 * Entry point of the banking system application.
 * Initializes the menu system and starts user interaction.
 */
int main()
{
    // Print a welcome message
    cout << "---------------------------------" << endl;
    cout << " Welcome to the Banking System! " << endl;
    cout << "---------------------------------" << endl;

    // Create a Menu object to manage the system
    Menu menu;

    // Start the menu system
    menu.start();

    // Exit message
    cout << "Thank you for using the Banking System. Goodbye!" << endl;
    return 0;
}
