#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "BankAccount.h"

/**
 * Checking Account class
 */
class CheckingAccount : public BankAccount {
private:
    double overdraft_limit;

public:
    /**
     * Default constructor
     */
    CheckingAccount();

    /**
     * Constructor with initial balance
     * @param initialBalance Initial account balance
     */
    explicit CheckingAccount(double initialBalance);

    /**
     * Check if overdraft limit is exceeded
     */
    void check_overdraft();

    /**
     * Apply overdraft fee
     */
    void apply_overdraft_fee();
};

#endif
