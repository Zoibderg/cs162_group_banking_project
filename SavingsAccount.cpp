#include "BankAccount.h"
#include <iostream>
using namespace std;

/**
 * SavingsAccount class represents a savings account derived from the base BankAccount class.
 * It provides additional functionality specific to savings accounts, such as interest calculations and penalties.
 */
class SavingsAccount : public BankAccount 
{
public:
    double interest_rate = 1.05; // Interest rate for the savings account
    double withdraw_amount{}; // Amount to be withdrawn

    /**
     * Constructor to initialize the savings account with account details.
     * @param accountNumber The unique number of the account.
     * @param holderName The name of the account holder.
     * @param initialBalance The initial balance of the account.
     */
    SavingsAccount(int accountNumber, const string &holderName, double initialBalance)
        : BankAccount(accountNumber, holderName, "Savings", "Active", initialBalance) {}

    /**
     * Method to calculate interest based on the current balance.
     * This method calculates interest using the defined interest rate.
     */
    static void calculate_interest()
    {
       interestBalance = initalBalance * interest_rate; 
        interestaccumulated = interestBalance - initialBalance; 
    }

    /**
     * Method to apply the calculated interest to the account balance.
     * This method will add the calculated interest to the current balance.
     */
    static void apply_interest()
    {
        cout << "Your current interest rate is 1.05%" << endl; 
        cout << " Total accumulated is: $" << interestaccumulated << endl; 
        cout << " Total Savings Balance: $" << interestBalance << endl; 
             
    }

    /**
     * Method to withdraw money, with additional logic for penalties if withdrawal amount is below $1000.
     */
    void withdraw() 
    {
        if (withdraw_amount < 1000.00) // Apply a penalty if the withdrawal amount is less than $1000
        {
            cout << " Withdraw penalty of $50.00 will be added" << endl;
            withdraw_amount += withdraw_penalty; // Add penalty to the withdrawal amount
            cout << " Total amount: $" << withdraw_amount << endl;
            cout << " === Current balance === " << endl;
            cout << "Current Balance: $" << getBalance() << "\n" << endl; // Display the current balance after the withdrawal
        }
    }

private:
    double withdraw_penalty = 50.00; // Penalty fee for withdrawals below a certain threshold
};
