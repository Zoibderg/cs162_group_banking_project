#include "Menu.h"
#include "MMDA.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "OneYearCD.h"
#include "ThreeMonthCD.h"
#include "SixMonthCD.h"
#include "Transaction.h"
#include <iostream>
#include <vector>
using namespace std;

vector<Transaction> transactions; // Transaction log to store all transactions

/**
 * Displays the Main Menu
 */
void Menu::displayMainMenu()
{
    cout << "\n===== Main Menu =====" << endl;
    cout << "1. Account Management" << endl;
    cout << "2. Transaction Management" << endl;
    cout << "3. Certificate of Deposit (CD) Management" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

/**
 * Displays the Account Management Menu
 */
void Menu::displayAccountMenu()
{
    int choice;

    do
    {
        cout << "\n===== Account Management Menu =====" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. View Account Details" << endl;
        cout << "3. Update Account Information" << endl;
        cout << "4. Delete Account" << endl;
        cout << "0. Return to Main Menu" << endl;
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
        case 0:
            cout << "Returning to Main Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

/**
 * Displays the Transaction Management Menu
 */
void Menu::displayTransactionMenu()
{
    int choice;

    do
    {
        cout << "\n===== Transaction Management Menu =====" << endl;
        cout << "1. Process Transaction" << endl;
        cout << "2. Cancel Transaction" << endl;
        cout << "0. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            processTransaction(); // Process a new transaction
            break;
        case 2:
            cancelTransaction(); // Cancel an existing transaction
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
 * Processes a new transaction
 */
void Menu::processTransaction()
{
    int accountNumber;
    string type;
    double amount;
    string date;

    cout << "\n===== Process Transaction =====" << endl;
    cout << "Enter account number: ";
    cin >> accountNumber;

    BankAccount* account = container.findAccount(accountNumber);
    if (account != nullptr)
    {
        cout << "Enter transaction type (Deposit/Withdrawal): ";
        cin >> type;
        cout << "Enter transaction amount: $";
        cin >> amount;
        cout << "Enter transaction date (YYYY-MM-DD): ";
        cin >> date;

        // Perform the transaction
        if (type == "Deposit")
        {
            account->setBalance(account->getBalance() + amount);
            cout << "Deposit of $" << amount << " was successful." << endl;
        }
        else if (type == "Withdrawal")
        {
            if (account->getBalance() >= amount)
            {
                account->setBalance(account->getBalance() - amount);
                cout << "Withdrawal of $" << amount << " was successful." << endl;
            }
            else
            {
                cout << "Insufficient funds. Transaction failed." << endl;
                return;
            }
        }
        else
        {
            cout << "Invalid transaction type." << endl;
            return;
        }

        // Log the transaction
        static int transactionId = 1;
        transactions.emplace_back(transactionId++, type, amount, date, accountNumber);

        cout << "Transaction logged successfully." << endl;
    }
    else
    {
        cout << "Account not found. Transaction failed." << endl;
    }
}

/**
 * Cancels an existing transaction
 */
void Menu::cancelTransaction()
{
    int transactionId;

    cout << "\n===== Cancel Transaction =====" << endl;
    cout << "Enter the transaction ID to cancel: ";
    cin >> transactionId;

    // Find the transaction
    auto it = find_if(transactions.begin(), transactions.end(), [transactionId](const Transaction& t) {
        return t.getTransactionId() == transactionId;
        });

    if (it != transactions.end())
    {
        // Retrieve transaction details
        const Transaction& transaction = *it;
        int accountNumber = transaction.getAccountNumber();
        double amount = transaction.getAmount();
        string type = transaction.getTransactionType();

        // Reverse the transaction
        BankAccount* account = container.findAccount(accountNumber);
        if (account != nullptr)
        {
            if (type == "Deposit")
            {
                account->setBalance(account->getBalance() - amount);
                cout << "Deposit of $" << amount << " has been cancelled." << endl;
            }
            else if (type == "Withdrawal")
            {
                account->setBalance(account->getBalance() + amount);
                cout << "Withdrawal of $" << amount << " has been cancelled." << endl;
            }

            // Remove the transaction from the log
            transactions.erase(it);
            cout << "Transaction cancelled successfully." << endl;
        }
        else
        {
            cout << "Account not found. Transaction reversal failed." << endl;
        }
    }
    else
    {
        cout << "Transaction ID not found." << endl;
    }
}
/**
 * Handles the addition of new accounts
 */
void Menu::addAccount()
{
    // Code for adding accounts remains unchanged
}

/**
 * Displays Account Details
 */
void Menu::viewAccountDetails()
{
    // Code for viewing account details remains unchanged
}

/**
 * Updates Account Information
 */
void Menu::updateAccountInformation()
{
    // Code for updating account information remains unchanged
}

/**
 * Deletes an account by account number
 */
void Menu::deleteAccount()
{
    int accountNumber;

    cout << "\n===== Delete Account =====" << endl;
    cout << "Enter the account number to delete: ";
    cin >> accountNumber;

    BankAccount* account = container.findAccount(accountNumber);

    if (account != nullptr)
    {
        char confirmation;
        cout << "Are you sure you want to delete this account? (y/n): ";
        cin >> confirmation;

        if (tolower(confirmation) == 'y')
        {
            if (container.removeAccount(accountNumber))
            {
                cout << "Account successfully deleted." << endl;
            }
            else
            {
                cout << "Failed to delete the account. Please try again." << endl;
            }
        }
        else
        {
            cout << "Account deletion cancelled." << endl;
        }
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

/**
 * Selects or creates a new customer
 */
Customer* Menu::selectOrCreateCustomer()
{
    // Code for selecting or creating customers remains unchanged
}
