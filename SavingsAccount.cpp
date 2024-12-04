//
// Created by Austin Tesch on 12/4/24.
//

#include "SavingsAccount.h"
#include "BankAccount.h"
#include <iostream>
using namespace std;

class SavingsAccount : public BankAccount
{
public:
    double interest_rate = 1.05;
    double withdrawlamount;
    void calcuate_interest() // calculates the interest based on the amount in the users account
    {

    }

    void apply_interest() // applys the interest to the account
    {

    }
    void Withdrawl()
    {
        if (withdrawlamount < 1000.00) // applys the penalty is the user withdrawls more than $1000
        {
            cout << " Withdrawl penalty of $50.00 will be added" << endl;
            withdrawl_penalty += withdrawlamount; // adds penalty to withdrawl amount
            cout << " Total amount: $" << withdrawlamount << endl;
            cout << " === Current balance === " << endl;
            get_current_balance(); // displays current balance after the withdrawl
        }
    }

private:
    double withdrawl_penalty = 50.00;
};