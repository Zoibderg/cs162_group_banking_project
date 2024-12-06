#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"

/**
 * @class SavingsAccount
 * @brief Represents a savings account with interest earning capability
 * 
 * This class implements a savings account that earns interest over time.
 * It extends the base BankAccount class with interest calculation and
 * APR application functionality.
 */
class SavingsAccount : public BankAccount {
private:
    double interest_rate;  ///< Annual interest rate for the account

public:
    /**
     * @brief Default constructor
     */
    SavingsAccount();

    /**
     * @brief Constructor with initial balance
     * @param initialBalance Initial deposit amount
     */
    explicit SavingsAccount(double initialBalance);

    /**
     * @brief Calculates interest earned on current balance
     * @return Calculated interest amount
     */
    double calculate_interest() const;

    /**
     * @brief Applies earned interest to account balance
     * @details Calculates and adds interest to the current balance
     */
    void apply_APR();
};

#endif
