#include "CheckingAccount.h"

/**
 * @brief Default constructor for CheckingAccount
 * @details Initializes a checking account with zero balance and standard overdraft limit
 */
CheckingAccount::CheckingAccount()
    : BankAccount(0, nullptr, "Checking", "Active", 0.0),
      overdraft_limit(500.0) {}

/**
 * @brief Constructor with initial balance
 * @param initialBalance Initial deposit amount
 * @details Creates a checking account with specified balance and standard overdraft limit
 */
CheckingAccount::CheckingAccount(double initialBalance)
    : BankAccount(0, nullptr, "Checking", "Active", initialBalance),
      overdraft_limit(500.0) {}

/**
 * @brief Checks if account has exceeded overdraft limit
 * @details Applies overdraft fee if balance is negative and exceeds limit
 */
void CheckingAccount::check_overdraft() {
    if (getBalance() < 0 && std::abs(getBalance()) > overdraft_limit) {
        apply_overdraft_fee();
    }
}

/**
 * @brief Applies standard overdraft fee
 * @details Deducts $35 fee from account balance when called
 */
void CheckingAccount::apply_overdraft_fee() {
    withdraw(35.0); // Standard overdraft fee
}
