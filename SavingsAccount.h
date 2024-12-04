#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"
#include <string>

/**
 * SavingsAccount class represents a savings account derived from the base BankAccount class.
 * It provides additional functionality specific to savings accounts, such as interest calculations and penalties.
 */
class SavingsAccount : public BankAccount
{
public:
    double interest_rate = 1.05; // Interest rate for the savings account
    double withdraw_amount; // Amount to be withdrawn

    /**
     * Constructor to initialize the savings account with account details.
     */
    SavingsAccount(int accountNumber, const std::string &holderName, double initialBalance);

    /**
     * Method to calculate interest based on the current balance.
     */
    void calculate_interest();

    /**
     * Method to apply the calculated interest to the account balance.
     */
    void apply_interest();

    /**
     * Method to withdraw money, with additional logic for penalties.
     */
    void withdraw();

private:
    double withdraw_penalty = 50.00; // Penalty fee for withdrawals below a certain threshold
};

#endif // SAVINGSACCOUNT_H
