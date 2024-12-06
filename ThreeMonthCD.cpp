#include <iostream>
#include "CertificateOfDepositBase.h"
#include "BankAccount.h"
using namespace std; 
class ThreeMonthCD : public BankAccount
{
public:
/* default contructor
*/
void ThreeMonthCD(double balance) 
	/*
	shows how long the duration of the Cd is
	*/
	time_t duration = 3;
	/*
	shows the apy for the specific Cd duration
	*/
	double apy = 0.025;
	/*
	the penalty for the specifc Cd duration
	*/
	double penalty = 0.1;
	/*
	calculates the penalty using the customers current balance
	and the penatly percentage for the CD
	*/
	double calculatePentaly()
	{
		double finalpenalty = balance * penalty;
	}
	/*
	calculates the interest earned based on the apy and duration
	for that CD
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
		cout << "Your penatly is: " << finalpenalty << endl;
		balance += finalpenalty
	}
	/*
	applies the interest to the users account
	*/
	void applyInterest()
	{
		cout << " Your interest is: " << interest << endl;
		balance += interest;
	}

};
