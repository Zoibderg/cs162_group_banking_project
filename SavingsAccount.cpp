#include "SavingsAccount.h"

/**
 * @brief Constructor with initial balance
 * @param initialBalance Initial deposit amount
 * @details Creates a savings account with specified balance and 2.5% interest rate
 */
SavingsAccount::SavingsAccount(double initialBalance)
    : BankAccount(0, nullptr, "Savings", "Active", initialBalance),
      interest_rate(0.025) {} // 2.5% interest rate

/**
 * @brief Calculates interest on current balance
 * @return Calculated interest amount
 * @details Computes interest based on current balance and account's interest rate
 */
double SavingsAccount::calculate_interest() const {
    return getBalance() * interest_rate;
}

/**
 * @brief Applies annual percentage rate to account
 * @details Calculates and deposits interest into the account
 */
void SavingsAccount::apply_APR() {
    double interest = calculate_interest();
    deposit(interest);
}
