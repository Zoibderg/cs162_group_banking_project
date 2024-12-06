#include "menu.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "SixMonthCD.h"
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
        cout << "2. View Account Details" << endl;
        cout << "3. Update Account Information" << endl;
        cout << "4. Delete Account" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
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

// Views account details by account number
void Menu::viewAccountDetails()
{
    int accountNumber;
    cout << "Enter Account Number to view details: ";
    cin >> accountNumber;

    BankAccount* account = container.findAccountByNumber(accountNumber);
    if (account)
    {
        account->displayAccountDetails();
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

// Updates account information (placeholder)
void Menu::updateAccountInformation()
{
    cout << "Updating account information is under development." << endl;
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
        cout << "Account deleted successfully." << endl;
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
}
