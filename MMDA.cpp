#include "MMDA.h"

/**
 * @brief Default constructor for MMDA
 * @details Initializes a Money Market Deposit Account with zero balance
 */
MMDA::MMDA() 
    : BankAccount(0, nullptr, "MMDA", "Active", 0.0), handler(nullptr) {
}

/**
 * @brief Constructor with initial balance
 * @param initialBalance Initial deposit amount
 * @details Creates an MMDA with specified initial balance
 */
MMDA::MMDA(double initialBalance)
    : BankAccount(0, nullptr, "MMDA", "Active", initialBalance), handler(nullptr) {
}

/**
 * @brief Destructor
 * @details Cleans up the balance handler if one exists
 */
MMDA::~MMDA() {
    delete handler;
}

/**
 * @brief Withdraws money from the account
 * @param amount Amount to withdraw
 * @details Processes withdrawal if sufficient funds are available
 */
void MMDA::withdraw(double amount) {
    if (amount <= getBalance()) {
        setBalance(getBalance() - amount);
    }
}

/**
 * @brief Applies penalty to the account
 * @details Calculates and deducts withdrawal penalty from balance
 */
void MMDA::applyPenalty() {
    double penalty = withdrawalPenalty(getBalance());
    setBalance(getBalance() - penalty);
}

/**
 * @brief Sets the balance of the account
 * @param newBalance New balance amount
 * @details Updates account balance if new balance is non-negative
 */
void MMDA::setBalance(double newBalance) {
    if (newBalance >= 0) {
        BankAccount::withdraw(getBalance());
        BankAccount::deposit(newBalance);
    }
}

/**
 * @brief Gets the current balance
 * @return Current account balance
 */
double MMDA::getBalance() const {
    return BankAccount::getBalance();
} 