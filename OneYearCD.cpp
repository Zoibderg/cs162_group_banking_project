#include <iostream>
#include "CertificateOfDepositBase.h"

class OneYearCD : public BankAccount
{
public:

	time_t duration = 12;
	double apy = 0.05;
	double penalty = 0.5;
	/*
	calculates the interest using the apy and duration for
	the specifc CD
	*/
	double calculateInterest()
	{
		double interest = apy * duration;
	}
	/*
	calculates the penalty using the users current balance the
	penalty percentage for the specifc CD
	*/
	double calculatePenatly()
	{
		double finalpenalty = balance * penalty;
	}
	/*
	applies the interest to the customers account
	*/
	void applyInterest()
	{
		cout << " Your interest is: " << interest << endl;
		balance += interest;
	}
	/*
	applies the penalty to the users account.
	*/

	void applyPenalty()
	{
		cout << " Your penalty is: " << finalpenalty << endl;
		balance += finalpenalty;
	}

};