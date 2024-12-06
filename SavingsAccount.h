#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"

/**
 * Savings Account class
 */
class SavingsAccount : public BankAccount {
private:
    double interest_rate;

public:
    /**
     * Default constructor
     */
    SavingsAccount();

    /**
     * Constructor with initial balance
     * @param initialBalance Initial account balance
     */
    explicit SavingsAccount(double initialBalance);

    /**
     * Calculate interest
     */
    double calculate_interest() const;

    /**
     * Apply interest to the account
     */
    void apply_APR();
};

#endif
