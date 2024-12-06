#include "Menu.h"
#include "MMDA.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "OneYearCD.h"
#include "ThreeMonthCD.h"
#include "SixMonthCD.h"
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
                addAccount();
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
 * Handles the addition of new accounts
 */
void Menu::addAccount() {
    int accountChoice;
    double initialBalance;

    cout << "\n===== Add Account =====" << endl;
    cout << "Select Account Type:" << endl;
    cout << "1. Money Market Deposit Account (MMDA)" << endl;
    cout << "2. Checking Account" << endl;
    cout << "3. Savings Account" << endl;
    cout << "4. Credit Account" << endl;
    cout << "5. One Year Certificate of Deposit" << endl;
    cout << "6. Three Month Certificate of Deposit" << endl;
    cout << "7. Six Month Certificate of Deposit" << endl;
    cout << "Enter choice (1-7): ";
    cin >> accountChoice;

    cout << "Enter initial balance: $";
    cin >> initialBalance;

    // First, select or create a customer
    Customer* customer = selectOrCreateCustomer();
    if (customer == nullptr) {
        cout << "Customer creation/selection failed. Account not created." << endl;
        return;
    }

    BankAccount* newAccount = nullptr;

    switch (accountChoice) {
        case 1: {
            newAccount = new MMDA(initialBalance);
            break;
        }
        case 2: {
            newAccount = new CheckingAccount(initialBalance);
            break;
        }
        case 3: {
            newAccount = new SavingsAccount(initialBalance);
            break;
        }
        case 4: {
            newAccount = new CreditAccount(initialBalance);
            break;
        }
        case 5: {
            newAccount = new OneYearCD(initialBalance);
            break;
        }
        case 6: {
            newAccount = new ThreeMonthCD(initialBalance);
            break;
        }
        case 7: {
            newAccount = new SixMonthCD(initialBalance);
            break;
        }
        default: {
            cout << "Invalid account type selected." << endl;
            return;
        }
    }

    if (newAccount != nullptr) {
        // Generate a unique account number
        static int accountCounter = 1000; // Starting account number
        newAccount->setAccountNumber(accountCounter++);
        
        // Set the account holder
        newAccount->setCustomer(customer);

        // Add the account to the container
        container.addAccount(newAccount);

        cout << "\nAccount created successfully!" << endl;
        cout << "Account Number: " << newAccount->getAccountNumber() << endl;
    }
}

/**
 * Helper function to select or create a customer
 * @return Pointer to selected or created customer, nullptr if operation fails
 */
Customer* Menu::selectOrCreateCustomer() {
    int choice;
    cout << "\nCustomer Selection:" << endl;
    cout << "1. Existing Customer" << endl;
    cout << "2. New Customer" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        string id;
        cout << "Enter Customer ID: ";
        cin >> id;
        return container.findCustomer(id);
    }
    else if (choice == 2) {
        string firstName, lastName, id;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Customer ID: ";
        cin >> id;

        // Check if customer ID already exists
        if (container.findCustomer(id) != nullptr) {
            cout << "Customer ID already exists." << endl;
            return nullptr;
        }

        Customer* newCustomer = new Customer(id, firstName, lastName);
        container.addCustomer(newCustomer);
        return newCustomer;
    }
    
    cout << "Invalid choice." << endl;
    return nullptr;
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
