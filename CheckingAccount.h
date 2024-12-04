#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"
#include <string>

/**
 * CheckingAccount class represents a checking account derived from the base BankAccount class.
 * It provides additional functionality specific to checking accounts, such as overdraft checks and fees.
 */
class CheckingAccount : public BankAccount
{
public:
    double account_balance; // Current balance of the checking account

    /**
     * Constructor to initialize the checking account with account details.
     */
    CheckingAccount(int accountNumber, const std::string &holderName, double initialBalance);

    /**
     * Method to check if the account balance has gone negative.
     * If the balance is negative, an overdraft fee will be applied.
     * If the balance is positive, no fee is applied.
     */
    void check_overdraft();

    /**
     * Method to apply the overdraft fee to the account balance.
     * Deducts a fixed overdraft fee from the current balance.
     */
    void apply_overdraft_fee();

private:
    double overdraft_limit; // Limit for overdrafts on the account
    double interest = 0.02; // Interest rate for the checking account
    double overdraft_fee = 25.00; // Fee for overdrawing the account
};

#endif // CHECKINGACCOUNT_H
