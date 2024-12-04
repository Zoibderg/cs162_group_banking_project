#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "BankAccount.h"
#include <string>

/**
 * CreditAccount class represents a credit account derived from the base BankAccount class.
 * It provides additional functionality specific to credit accounts, such as minimum payment calculations.
 */
class CreditAccount : public BankAccount
{
public:
    double APR; // Annual Percentage Rate for the credit account

    /**
     * Constructor to initialize the credit account with account details.
     */
    CreditAccount(int accountNumber, const std::string &holderName, double initialBalance);

    /**
     * Method to calculate the minimum payment required for the credit account.
     */
    void calculate_min_payment();

private:
    double credit_limit; // Limit for the credit account
    double current_balance; // Current balance for the credit account
};

#endif // CREDITACCOUNT_H
