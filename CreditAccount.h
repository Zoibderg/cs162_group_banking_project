#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include "BankAccount.h"

/**
 * @class CreditAccount
 * @brief Represents a credit account with credit limit and APR
 * 
 * This class implements a credit account with features like credit limit,
 * minimum payment calculation, and APR tracking. It extends the base
 * BankAccount class with credit-specific functionality.
 */
class CreditAccount : public BankAccount {
private:
    double credit_limit;   ///< Maximum allowed credit limit
    double APR;           ///< Annual Percentage Rate
    double min_payment;   ///< Minimum required payment amount

public:
    /**
     * @brief Default constructor
     */
    CreditAccount();

    /**
     * @brief Constructor with initial balance
     * @param initialBalance Initial credit balance
     */
    explicit CreditAccount(double initialBalance);

    /**
     * @brief Calculates the minimum required payment
     * @return Minimum payment amount
     */
    double calculate_minimum_payment() const;

    /**
     * @brief Verifies if transaction is within credit limit
     * @return true if within limit, false otherwise
     */
    bool check_credit_limit() const;
};

#endif
