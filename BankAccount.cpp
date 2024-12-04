#include "BankAccount.h"
#include <iostream>
using namespace std;

/**
 * Virtual destructor ensures that derived class destructors are called properly.
 */
BankAccount::~BankAccount() = default;

/**
 * Constructor to initialize the bank account with provided details.
 * @param accountNumber The unique number of the account.
 * @param holderName The name of the account holder.
 * @param accountType The type of the account (e.g., "Savings", "Checking").
 * @param status The initial status of the account (must be "Active", "Closed", or "Frozen").
 * @param initialBalance The initial balance of the account.
 */
BankAccount::BankAccount(int accountNumber, const string &holderName, const string &accountType, const string &status,
                         double initialBalance)
    : account_number(accountNumber), balance(initialBalance), account_holder(holderName),
      account_type(accountType),
      account_status((status == "Active" || status == "Closed" || status == "Frozen") ? status : "Active") {
}

/**
 * Method to deposit money into the account.
 * @param amount The amount to be deposited. Must be a positive value.
 */
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactions.push_back("Deposit: $" + to_string(amount));
        cout << "Successfully deposited: $" << amount << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
    displayBalance();
}

/**
 * Method to withdraw money from the account.
 * @param amount The amount to be withdrawn. Must be a positive value and must not exceed the current balance.
 */
void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactions.push_back("Withdrawal: $" + to_string(amount));
        cout << "Successfully withdrew: $" << amount << endl;
    } else {
        cout << "Invalid withdrawal amount or insufficient funds." << endl;
    }
    displayBalance();
}

/**
 * Getter for the current balance of the account.
 * @return The current balance as a double.
 */
double BankAccount::getBalance() const {
    return balance;
}

/**
 * Getter for the account holder's name.
 * @return The account holder's name as a string.
 */
string BankAccount::getAccountHolder() const {
    return account_holder;
}

/**
 * Getter for the type of the account.
 * @return The account type as a string.
 */
string BankAccount::getAccountType() const {
    return account_type;
}

/**
 * Getter for the current status of the account.
 * @return The account status as a string.
 */
string BankAccount::getAccountStatus() const {
    return account_status;
}

/**
 * Method to generate and print the account statement, including all relevant details and transaction history.
 */
void BankAccount::generateStatement() const {
    cout << "\nAccount Statement:" << endl;
    cout << "Account Holder: " << account_holder << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Account Type: " << account_type << endl;
    cout << "Account Status: " << account_status << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Transactions: " << endl;
    for (const auto &transaction : transactions) {
        cout << " - " << transaction << endl;
    }
}

/**
 * Private method to display the current balance.
 */
void BankAccount::displayBalance() const {
    cout << "Current Balance: $" << balance << "\n" << endl;
}

