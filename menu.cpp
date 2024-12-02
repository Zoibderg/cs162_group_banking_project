//
// Created by Austin Tesch on 12/2/24.
//
#include "Menu.h"
#include <iostream>
using namespace std;

/**
 * Displays the main menu with options for account management, transaction management,
 * and certificate of deposit (CD) management.
 */
void Menu::displayMainMenu() {
    cout << "\n===== Main Menu =====" << endl;
    cout << "1. Account Management" << endl;
    cout << "2. Transaction Management" << endl;
    cout << "3. Certificate of Deposit (CD) Management" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

/**
 * Displays the account management menu with options to add, view, update, or delete accounts.
 * Loops until the user chooses to return to the main menu.
 */
void Menu::displayAccountMenu() {
    int choice;
    do {
        cout << "\n===== Account Management Menu =====" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. View Account Details" << endl;
        cout << "3. Update Account Information" << endl;
        cout << "4. Delete Account" << endl;
        cout << "0. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add Account functionality is not yet implemented." << endl;
                break;
            case 2:
                cout << "View Account Details functionality is not yet implemented." << endl;
                break;
            case 3:
                cout << "Update Account Information functionality is not yet implemented." << endl;
                break;
            case 4:
                cout << "Delete Account functionality is not yet implemented." << endl;
                break;
            case 0:
                cout << "Returning to Main Menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

/**
 * Displays the transaction management menu with options to process or cancel transactions.
 * Loops until the user chooses to return to the main menu.
 */
void Menu::displayTransactionMenu() {
    int choice;
    do {
        cout << "\n===== Transaction Management Menu =====" << endl;
        cout << "1. Process Transaction" << endl;
        cout << "2. Cancel Transaction" << endl;
        cout << "0. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Process Transaction functionality is not yet implemented." << endl;
                break;
            case 2:
                cout << "Cancel Transaction functionality is not yet implemented." << endl;
                break;
            case 0:
                cout << "Returning to Main Menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

/**
 * Displays the Certificate of Deposit (CD) management menu with options to add, view details,
 * apply interest, or apply penalties to CDs. Loops until the user chooses to return to the main menu.
 */
void Menu::displayCDMenu() {
    int choice;
    do {
        cout << "\n===== Certificate of Deposit (CD) Management Menu =====" << endl;
        cout << "1. Add Certificate of Deposit" << endl;
        cout << "2. View CD Details" << endl;
        cout << "3. Apply Interest to CD" << endl;
        cout << "4. Apply Penalty to CD" << endl;
        cout << "0. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add Certificate of Deposit functionality is not yet implemented." << endl;
                break;
            case 2:
                cout << "View CD Details functionality is not yet implemented." << endl;
                break;
            case 3:
                cout << "Apply Interest to CD functionality is not yet implemented." << endl;
                break;
            case 4:
                cout << "Apply Penalty to CD functionality is not yet implemented." << endl;
                break;
            case 0:
                cout << "Returning to Main Menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}
