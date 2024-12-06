#ifndef Three_Month_CD_H 
#define Three_Month_CD_H 

#include "CertificateOfDepositbase.h"
#include "BankAccount.h"

// class for handling Three Month CD operations 
class ThreeMonthCD
{
public:
time_t duration;
double apy;
double penalty; 
// defaul constructor
ThreeMonthCD() = default;
// function for adding the interest to the customers account
 void applyInterest(double apy, time_t duration); 
// function for adding the penalty to the customers account 
 void applyPenalty(double balance, double penalty); 
// function to calculate the penalty for the customer 
double calculatePenalty(); 
// function to calculate the interest for the customer 
double calculateInterest();
// deconstructor 
 ~ThreeMonthCD();
};

#endif 
