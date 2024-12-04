#include "CheckingAccount.h"
#include "BankAccount.h"
#include <iostream>
using namespace std;

class CheckingAccount : public BankAccount
{
public:
    double accountbalance;
    void check_overdraft() // checks to see if the user is negative in the account
    {
        if (accountbalance < 0)
        {
            cout << " Account balance went negative. Overdraft fee of $25.00 being applied" << endl;
        }
        else if (accountbalance > 0)
        {
            cout << " No overdraft fee applied" << endl;
        }
    }
    void apply_overdraft_fee() // apples the over draft fee to the users account
    {
        accountbalance -= overdraftfee;
        cout << " === Current Account Balance === " << endl;
        get_current_balance();
    }

private:
    double overdraft_limit;
    double interest = 0.02;
    double overdraftfee = 25.00;
};