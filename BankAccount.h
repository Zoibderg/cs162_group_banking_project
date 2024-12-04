#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>

class BankAccount {
public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~BankAccount();

    // Constructor to initialize the bank account with details
    BankAccount(int accountNumber, const std::string &holderName, const std::string &accountType, const std::string &status, double initialBalance);

    // Deposits an amount into the account, must be a positive value
    virtual void deposit(double amount);

    // Withdraws an amount from the account, must be positive and not exceed the current balance
    virtual void withdraw(double amount);

    // Returns the current balance of the account
    [[nodiscard]] double getBalance() const;

    // Returns the name of the account holder
    [[nodiscard]] std::string getAccountHolder() const;

    // Returns the type of the account (e.g., "Savings", "Checking")
    [[nodiscard]] std::string getAccountType() const;

    // Returns the current status of the account (e.g., "Active", "Closed")
    [[nodiscard]] std::string getAccountStatus() const;

    // Generates a statement containing all relevant account details and transaction history
    void generateStatement() const;

private:
    int account_number; // Unique identifier for the account
    double balance; // Current balance of the account
    std::string account_holder; // Name of the account holder
    std::string account_type; // Type of the account (e.g., "Savings", "Checking")
    std::string account_status; // Status of the account (e.g., "Active", "Closed")
    std::vector<std::string> transactions; // List of transactions performed on the account

    // Displays the current balance of the account to the console
    void displayBalance() const;
};

#endif // BANKACCOUNT_H
