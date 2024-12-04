#include "CreditAccount.h"
#include "BankAccount.h"

class CreditAccount : public BankAccount
{
public:
    double APR;

    void calculate_min_payment() // calculates the minimum payment user must make on the credit cardd
    {

    }

private:
    double credit_limit;
    double current_balance;

};