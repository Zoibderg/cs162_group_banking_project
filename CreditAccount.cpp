#include "BankAccount.h"
#include <iostream>
using namespace std;

/**
 * CreditAccount class represents a credit account derived from the base BankAccount class.
 * It provides additional functionality specific to credit accounts, such as managing credit limit, calculating minimum payments, and making charges.
 */
class CreditAccount : public BankAccount
{
public:
    double APR; // Annual Percentage Rate for the credit account

    /**
     * Constructor to initialize the credit account with account details.
     * @param accountNumber The unique number of the account.
     * @param holderName The name of the account holder.
     * @param initialBalance The initial balance of the account.
     * @param apr The annual percentage rate for the account.
     * @param limit The credit limit for the account.
     */
    CreditAccount(int accountNumber, const string &holderName, double initialBalance, double apr, double limit)
        : BankAccount(accountNumber, holderName, "Credit", "Active", initialBalance), APR(apr), credit_limit(limit), current_balance(initialBalance) {}

    /**
     * Method to calculate the minimum payment required for the credit account.
     * The minimum payment is assumed to be 5% of the current balance.
     */
    void calculate_min_payment() const
    {
        double min_payment = 0.05 * current_balance;
        cout << "The minimum payment for this account is: $" << min_payment << endl;
    }

    /**
     * Method to make a payment towards the credit balance.
     * @param amount The amount to be paid. Must be greater than zero.
     */
    void make_payment(double amount)
    {
        if (amount > 0)
        {
            current_balance -= amount;
            cout << "Payment of $" << amount << " has been made. Current balance: $" << current_balance << endl;
        }
        else
        {
            cout << "Invalid payment amount." << endl;
        }
    }

    /**
     * Method to charge the credit account (i.e., make a purchase).
     * @param amount The amount to be charged. Must be greater than zero and not exceed the credit limit.
     */
    void charge(double amount)
    {
        if (amount > 0 && (current_balance + amount) <= credit_limit)
        {
            current_balance += amount;
            cout << "Charge of $" << amount << " has been added. Current balance: $" << current_balance << endl;
        }
        else
        {
            cout << "Charge exceeds credit limit or is invalid." << endl;
        }
    }

private:
    double credit_limit; // Limit for the credit account
    double current_balance; // Current balance for the credit account
};
