#include "BankAccount.h"
#include <iostream>
using namespace std;

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
     * @param accountNumber The unique number of the account.
     * @param holderName The name of the account holder.
     * @param initialBalance The initial balance of the account.
     */
    CheckingAccount(int accountNumber, const string &holderName, double initialBalance)
        : BankAccount(accountNumber, holderName, "Checking", "Active", initialBalance),
          account_balance(initialBalance) {
    }

    /**
     * Method to check if the account balance has gone negative.
     * If the balance is negative, an overdraft fee will be applied.
     * If the balance is positive, no fee is applied.
     */
    void check_overdraft() const
    {
        if (account_balance < 0) // If the balance is negative, apply an overdraft fee
        {
            cout << " Account balance went negative. Overdraft fee of $25.00 being applied" << endl;
        }
        else if (account_balance > 0) // If the balance is positive, no fee is applied
        {
            cout << " No overdraft fee applied" << endl;
        }
    }

    /**
     * Method to apply the overdraft fee to the account balance.
     * Deducts a fixed overdraft fee from the current balance.
     */
    void apply_overdraft_fee()
    {
        account_balance -= overdraft_fee; // Deduct the overdraft fee from the account balance
        cout << " === Current Account Balance === " << endl;
        cout << "Current Balance: $" << getBalance() << "\n" << endl; // Display the updated balance
    }

    // Default constructor
    CheckingAccount()
        : BankAccount(), overdraft_limit(500.0) {
    }

    // Constructor with initial balance
    CheckingAccount(double initialBalance)
        : BankAccount(initialBalance), overdraft_limit(500.0) {
    }

    // Check if overdraft limit is exceeded
    void check_overdraft() {
        if (getBalance() < 0) {
            if (std::abs(getBalance()) > overdraft_limit) {
                std::cout << "Warning: Account is over the overdraft limit!" << std::endl;
                apply_overdraft_fee();
            } else {
                std::cout << "Account is in overdraft but within limit." << std::endl;
            }
        }
    }

    // Apply overdraft fee
    void apply_overdraft_fee() {
        const double OVERDRAFT_FEE = 35.0;
        setBalance(getBalance() - OVERDRAFT_FEE);
        std::cout << "Overdraft fee of $" << OVERDRAFT_FEE << " has been applied." << std::endl;
        std::cout << "New balance: $" << getBalance() << std::endl;
    }

private:
    double overdraft_limit{}; // Limit for overdrafts on the account
    double interest = 0.02; // Interest rate for the checking account
    double overdraft_fee = 25.00; // Fee for overdrawing the account
};
