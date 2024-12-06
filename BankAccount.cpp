#include "BankAccount.h"
#include "Customer.h"

/**
 * @brief Constructs a new bank account with specified parameters
 * 
 * @param accountNumber Unique identifier for the account
 * @param holder Pointer to the account holder
 * @param type Type of account (e.g., "Checking", "Savings")
 * @param status Initial account status
 * @param initialBalance Initial deposit amount
 */
BankAccount::BankAccount(int accountNumber, Customer* holder, const std::string& type,
                        const std::string& status, double initialBalance)
    : accountNumber(accountNumber), accountHolder(holder), accountType(type),
      accountStatus(status), balance(initialBalance) {}

/**
 * @brief Deposits money into the account
 * 
 * @param amount Amount to deposit
 * @details Adds the amount to the balance and records the transaction if amount is positive
 */
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactions.push_back("Deposit: $" + std::to_string(amount));
    }
}

/**
 * @brief Withdraws money from the account
 * 
 * @param amount Amount to withdraw
 * @details Subtracts the amount from balance if sufficient funds are available
 */
void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactions.push_back("Withdrawal: $" + std::to_string(amount));
    }
}

// Getter implementations
double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getAccountHolder() const {
    return accountHolder ? accountHolder->getFullName() : "No holder";
}

std::string BankAccount::getAccountType() const {
    return accountType;
}

std::string BankAccount::getAccountStatus() const {
    return accountStatus;
}

int BankAccount::getAccountNumber() const {
    return accountNumber;
}

// Setter implementations
void BankAccount::setAccountNumber(int number) {
    accountNumber = number;
}

void BankAccount::setCustomer(Customer* customer) {
    accountHolder = customer;
}

/**
 * @brief Generates a detailed statement of the account
 * 
 * @details Displays account holder information, account details,
 *          current balance, and transaction history
 */
void BankAccount::generateStatement() const {
    std::cout << "Account Holder: " << getAccountHolder() << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Type: " << accountType << std::endl;
    std::cout << "Account Status: " << accountStatus << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    std::cout << "Transactions: " << std::endl;
    for (const auto& transaction : transactions) {
        std::cout << transaction << std::endl;
    }
}

/**
 * @brief Displays basic account information
 * 
 * @details Shows account number, type, status, and current balance
 */
void BankAccount::displayAccountDetails() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Type: " << accountType << std::endl;
    std::cout << "Account Status: " << accountStatus << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
}

