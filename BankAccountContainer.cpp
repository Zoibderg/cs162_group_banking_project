#include "menu.h"
#include <iostream>
using namespace std;

// Starts the menu system by displaying the main menu
void Menu::start()
{
    displayMainMenu();
}

// Displays the main menu and processes user choices
void Menu::displayMainMenu()
{
    int choice;

    do
    {
        cout << "\nMain Menu:" << endl;
        cout << "1. Account Management" << endl;
        cout << "2. Transaction Management" << endl;
        cout << "3. CD Management" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAccountMenu();
            break;
        case 2:
            displayTransactionMenu();
            break;
        case 3:
            displayCDMenu();
            break;
        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

// Displays the account management menu and processes user choices
void Menu::displayAccountMenu()
{
    int choice;

    do
    {
        cout << "\nAccount Management Menu:" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. View All Accounts" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addAccount();
            break;
        case 2:
            container.displayAllCustomers();
            break;
        case 3:
            deleteAccount();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

// Adds a new account for a customer
void Menu::addAccount()
{
    cout << "Adding a new account..." << endl;
    Customer* customer = selectOrCreateCustomer();
    if (customer)
    {
        cout << "Select Account Type:" << endl;
        cout << "1. Checking Account" << endl;
        cout << "2. Savings Account" << endl;
        cout << "3. Credit Account" << endl;
        cout << "4. Six-Month CD Account" << endl;
        int choice;
        cin >> choice;

        BankAccount* account = nullptr;
        double initialBalance;
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        switch (choice)
        {
        case 1:
            account = new CheckingAccount(initialBalance);
            break;
        case 2:
            account = new SavingsAccount(initialBalance);
            break;
        case 3:
            account = new CreditAccount(initialBalance);
            break;
        case 4:
            account = new SixMonthCD(initialBalance);
            break;
        default:
            cout << "Invalid account type selected." << endl;
            return;
        }

        if (account)
        {
            container.addAccount(account);
            cout << "Account added successfully!" << endl;
        }
    }
}

// Deletes an account by account number
void Menu::deleteAccount()
{
    int accountNumber;
    cout << "Enter Account Number to delete: ";
    cin >> accountNumber;

    bool success = container.deleteAccount(accountNumber);
    if (success)
    {
        cout << "Account deleted successfully!" << endl;
    }
    else
    {
        cout << "Account not found or could not be deleted." << endl;
    }
}

// Allows selecting an existing customer or creating a new one
Customer* Menu::selectOrCreateCustomer()
{
    int choice;
    cout << "\nCustomer Selection:" << endl;
    cout << "1. Existing Customer" << endl;
    cout << "2. New Customer" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string id;
        cout << "Enter Customer ID: ";
        cin >> id;
        return container.findCustomerById(id);
    }
    else if (choice == 2)
    {
        string firstName, lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        Customer* newCustomer = new Customer(firstName, lastName);
        container.addCustomer(newCustomer);
        cout << "New customer created with ID: " << newCustomer->getId() << endl;
        return newCustomer;
    }
    else
    {
        cout << "Invalid choice." << endl;
        return nullptr;
    }

#include "BankAccountContainer.h"

    bool BankAccountContainer::deleteAccount(int accountNumber)
    {
        auto it = std::find_if(accounts.begin(), accounts.end(),
            [accountNumber](BankAccount* account)
            {
                return account->getAccountNumber() == accountNumber;
            });

        if (it != accounts.end())
        {
            delete* it; // Free memory
            accounts.erase(it); // Remove from the vector
            return true;
        }
        return false;
    }

    BankAccount* BankAccountContainer::findAccountByNumber(int accountNumber)
    {
        for (BankAccount* account : accounts)
        {
            if (account->getAccountNumber() == accountNumber)
            {
                return account;
            }
        }
        return nullptr;
    }

}
