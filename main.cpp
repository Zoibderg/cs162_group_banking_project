#include <iostream>
#include "Menu.h"
#include "BankAccountContainer.h"
using namespace std;

int main() {
    BankAccountContainer container;
    Menu menu(container);
    int choice;
    do {
        menu.displayMainMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                menu.displayAccountMenu();
            break;
            case 2:
                menu.displayTransactionMenu();
            break;
            case 3:
                menu.displayCDMenu();
            break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
