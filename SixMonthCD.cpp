#include <iostream>
#include "CertificateOfDepositBase.h"
using namepsace std;

class SixMonthCD : public BankAccount
{
public:
void SixMonthCD(double balance)

    time_t duration = 6;
    double apy = 0.03;
    double penalty = 0.2;
    /*
    calculates the penalty amount that will be applied to the customers
    balance by using the current balance and the penalty percentage
    */
    double calculatePenalty()
    {
        double finalPenalty = balance * penalty;
    }
    /*
    calculates the interest rate and adds it to the users account by using the apy and
    the duration
    */
    double calculateInterest()
    {
        double interest = apy * duration;
    }
    /*
    applies the penalty to the users account
    */
    void applyPenalty()
    {
        cout << " Your penalty is: " << finalPenalty << endl;
        balance += finalPentaly;
    }
    /*
    applies the interest to the users account
    */
    void applyInterest()
    {
        cout << " Your Interest is: " << interest << endl;
        balance += interest;
    }

};
