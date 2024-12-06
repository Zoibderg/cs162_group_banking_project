#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include "BankAccount.h"

/**
 * Credit Account class
 */
class CreditAccount : public BankAccount {
private:
    double credit_limit;
    double APR;
    double min_payment;

public:
    /**
     * Default constructor
     */
    CreditAccount();

    /**
     * Constructor with initial balance
     * @param initialBalance Initial account balance
     */
    explicit CreditAccount(double initialBalance);

    /**
     * Calculate minimum payment
     */
    double calculate_minimum_payment() const;

    /**
     * Check if credit limit is reached
     */
    bool check_credit_limit() const;
};

#endif
