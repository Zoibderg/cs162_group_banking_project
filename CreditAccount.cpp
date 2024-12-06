#include "CreditAccount.h"

/**
 * @brief Constructor with initial balance
 * @param initialBalance Initial credit balance
 * @details Initializes a credit account with specified balance, $5000 credit limit,
 *          19.95% APR, and $25 minimum payment
 */
CreditAccount::CreditAccount(double initialBalance)
    : BankAccount(0, nullptr, "Credit", "Active", initialBalance),
      credit_limit(5000.0), APR(0.1995), min_payment(25.0) {}

/**
 * @brief Calculates minimum payment required
 * @return Minimum payment amount
 * @details Returns greater of $25 or 2% of current balance
 */
double CreditAccount::calculate_minimum_payment() const {
    return std::max(min_payment, getBalance() * 0.02); // 2% of balance or $25, whichever is greater
}

/**
 * @brief Checks if transaction is within credit limit
 * @return true if within limit, false otherwise
 * @details Verifies that absolute value of balance doesn't exceed credit limit
 */
bool CreditAccount::check_credit_limit() const {
    return std::abs(getBalance()) <= credit_limit;
}
