#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include <iostream>

// Forward declaration of Customer class
class Customer;

/**
 * @class BankAccount
 * @brief Base class for all bank account types
 * 
 * This class provides the core functionality for bank accounts including
 * basic operations like deposits, withdrawals, and balance management.
 * It also maintains account holder information and transaction history.
 */
class BankAccount {
private:
    int accountNumber;              ///< Unique identifier for the account
    Customer* accountHolder;        ///< Pointer to the account holder
    std::string accountType;        ///< Type of account (e.g., "Checking", "Savings")
    std::string accountStatus;      ///< Current status of the account (e.g., "Active", "Closed")
    double balance;                 ///< Current balance in the account
    std::vector<std::string> transactions;  ///< History of transactions

public:
    /**
     * @brief Constructs a new bank account
     * @param accountNumber Unique identifier for the account
     * @param holder Pointer to the account holder
     * @param type Type of account
     * @param status Initial status of the account
     * @param initialBalance Initial deposit amount
     */
    BankAccount(int accountNumber, Customer* holder, const std::string& type, 
                const std::string& status, double initialBalance);

    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes
     */
    virtual ~BankAccount() = default;

    /**
     * @brief Deposits money into the account
     * @param amount Amount to deposit
     */
    virtual void deposit(double amount);

    /**
     * @brief Withdraws money from the account
     * @param amount Amount to withdraw
     */
    virtual void withdraw(double amount);
    
    // Getters
    virtual double getBalance() const;
    std::string getAccountHolder() const;
    std::string getAccountType() const;
    std::string getAccountStatus() const;
    int getAccountNumber() const;
    
    // Setters
    void setAccountNumber(int number);
    void setCustomer(Customer* customer);

    /**
     * @brief Generates a detailed statement of the account
     */
    void generateStatement() const;

    /**
     * @brief Displays basic account details
     */
    virtual void displayAccountDetails() const;
};

#endif
