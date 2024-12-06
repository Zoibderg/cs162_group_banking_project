#include "menu.h"
#include "MMDA.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "OneYearCD.h"
#include "ThreeMonthCD.h"
#include "SixMonthCD.h"
#include <iostream>
using namespace std;

namespace {
    bool getValidDoubleInput(double& value, const std::string& prompt) {
        std::cout << prompt;
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number.\n";
            return false;
        }
        if (value < 0) {
            std::cout << "Amount cannot be negative.\n";
            return false;
        }
        return true;
    }

    bool getValidIntInput(int& value, const std::string& prompt, int min, int max) {
        std::cout << prompt;
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number.\n";
            return false;
        }
        if (value < min || value > max) {
            std::cout << "Please enter a number between " << min << " and " << max << ".\n";
            return false;
        }
        return true;
    }
}

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
        cout << "5. List Accounts by Balance" << endl;
        cout << "6. List Accounts by Last Name" << endl;
        cout << "0. Return to Main Menu" << endl;
        
        if (!getValidIntInput(choice, "Enter your choice: ", 0, 6)) {
            continue;
        }

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccountDetails();
                break;
            case 3:
                updateAccountInformation();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                container.displayAccountsSortedByBalance();
                break;
            case 6:
                container.displayAccountsSortedByLastName();
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

    if (!getValidIntInput(accountChoice, "Enter choice (1-7): ", 1, 7)) {
        return;
    }

    if (!getValidDoubleInput(initialBalance, "Enter initial balance: $")) {
        return;
    }

    // First, select or create a customer
    Customer* customer = selectOrCreateCustomer();
    if (customer == nullptr) {
        cout << "Customer creation/selection failed. Account not created." << endl;
        return;
    }

    std::unique_ptr<BankAccount> newAccount;

    switch (accountChoice) {
        case 1:
            newAccount = std::make_unique<MMDA>(initialBalance);
            break;
        case 2:
            newAccount = std::make_unique<CheckingAccount>(initialBalance);
            break;
        case 3:
            newAccount = std::make_unique<SavingsAccount>(initialBalance);
            break;
        case 4:
            newAccount = std::make_unique<CreditAccount>(initialBalance);
            break;
        case 5:
            newAccount = std::make_unique<OneYearCD>(initialBalance);
            break;
        case 6:
            newAccount = std::make_unique<ThreeMonthCD>(initialBalance);
            break;
        case 7:
            newAccount = std::make_unique<SixMonthCD>(initialBalance);
            break;
        default:
            cout << "Invalid account type selected." << endl;
            return;
    }

    if (newAccount) {
        static int accountCounter = 1000;
        newAccount->setAccountNumber(accountCounter++);
        newAccount->setCustomer(customer);
        
        // Transfer ownership to container
        container.addAccount(newAccount.release());
        
        cout << "\nAccount created successfully!" << endl;
        cout << "Account Number: " << accountCounter - 1 << endl;
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
        return container.findCustomerById(id);
    }
    else if (choice == 2) {
        string firstName, lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;

        auto newCustomer = new Customer(firstName, lastName);
        while (container.findCustomerById(newCustomer->getId()) != nullptr) {
            delete newCustomer;
            newCustomer = new Customer(firstName, lastName);
        }

        container.addCustomer(newCustomer);
        cout << "Customer created with ID: " << newCustomer->getId() << endl;
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

        if (!getValidIntInput(choice, "Enter your choice: ", 0, 4)) {
            continue;
        }

        int accountNumber;
        BankAccount* account;

        switch (choice) {
            case 1:
                addAccount(); // This already handles CD creation
                break;
            case 2:
                viewAccountDetails(); // This already handles viewing CD details
                break;
            case 3:
                if (getValidIntInput(accountNumber, "Enter CD Account Number: ", 1000, 9999)) {
                    account = container.findAccountByNumber(accountNumber);
                    if (auto* cd = dynamic_cast<CertificateOfDepositBase*>(account)) {
                        double interest = cd->calculateInterest();
                        cd->setBalance(cd->getBalance() + interest);
                        cout << "Interest applied: $" << interest << endl;
                        cout << "New balance: $" << cd->getBalance() << endl;
                    } else {
                        cout << "This account is not a CD." << endl;
                    }
                }
                break;
            case 4:
                if (getValidIntInput(accountNumber, "Enter CD Account Number: ", 1000, 9999)) {
                    account = container.findAccountByNumber(accountNumber);
                    if (auto* cd = dynamic_cast<CertificateOfDepositBase*>(account)) {
                        double penalty = cd->getBalance() * 0.01; // 1% penalty
                        cd->setBalance(cd->getBalance() - penalty);
                        cout << "Penalty applied: $" << penalty << endl;
                        cout << "New balance: $" << cd->getBalance() << endl;
                    } else {
                        cout << "This account is not a CD." << endl;
                    }
                }
                break;
            case 0:
                cout << "Returning to Main Menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void Menu::viewAccountDetails() {
    int accountNumber;
    cout << "\n===== View Account Details =====" << endl;
    if (!getValidIntInput(accountNumber, "Enter Account Number: ", 1000, 9999)) {
        return;
    }

    BankAccount* account = container.findAccountByNumber(accountNumber);
    if (account) {
        account->generateStatement();
    } else {
        cout << "Account not found." << endl;
    }
}

void Menu::updateAccountInformation() {
    int accountNumber;
    cout << "\n===== Update Account Information =====" << endl;
    if (!getValidIntInput(accountNumber, "Enter Account Number: ", 1000, 9999)) {
        return;
    }

    BankAccount* account = container.findAccountByNumber(accountNumber);
    if (!account) {
        cout << "Account not found." << endl;
        return;
    }

    cout << "\nCurrent Account Details:" << endl;
    account->displayAccountDetails();

    cout << "\nWhat would you like to update?" << endl;
    cout << "1. Process Deposit" << endl;
    cout << "2. Process Withdrawal" << endl;
    cout << "0. Cancel" << endl;

    int choice;
    if (!getValidIntInput(choice, "Enter choice: ", 0, 2)) {
        return;
    }

    double amount;
    switch (choice) {
        case 1:
            if (getValidDoubleInput(amount, "Enter deposit amount: $")) {
                account->deposit(amount);
                cout << "Deposit processed successfully." << endl;
            }
            break;
        case 2:
            if (getValidDoubleInput(amount, "Enter withdrawal amount: $")) {
                if (amount <= account->getBalance()) {
                    account->withdraw(amount);
                    cout << "Withdrawal processed successfully." << endl;
                } else {
                    cout << "Insufficient funds." << endl;
                }
            }
            break;
        case 0:
            cout << "Update cancelled." << endl;
            break;
    }
}

void Menu::deleteAccount() {
    int accountNumber;
    cout << "\n===== Delete Account =====" << endl;
    if (!getValidIntInput(accountNumber, "Enter Account Number: ", 1000, 9999)) {
        return;
    }

    BankAccount* account = container.findAccountByNumber(accountNumber);
    if (!account) {
        cout << "Account not found." << endl;
        return;
    }

    cout << "\nAccount Details to be deleted:" << endl;
    account->displayAccountDetails();

    char confirm;
    cout << "\nAre you sure you want to delete this account? (y/n): ";
    cin >> confirm;

    if (tolower(confirm) == 'y') {
        if (container.deleteAccount(accountNumber)) {
            cout << "Account deleted successfully." << endl;
        } else {
            cout << "Error deleting account." << endl;
        }
    } else {
        cout << "Deletion cancelled." << endl;
    }
}

void Menu::start() {
    int choice;
    do {
        displayMainMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                displayAccountMenu();
                break;
            case 2:
                displayTransactionMenu();
                break;
            case 3:
                displayCDMenu();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}
