#ifndef Six_Month_CD_H 
#define Six_Month_CD_H 

#include "CertificateOfDepositbase.h"
#include "BankAccount.h"

// class for handling Six Month CD operations
class SixMonthCD
{
public:
  // defauly constructor 
SixMonthCD() = default;

time_t duration;
double apy;
double penalty; 

// function for applying interest to customers account

 void applyInterest(double apy, time_t duration); 
// function to calculate the interest for the customer
 double calculateInterest();  

// function for applying penalty to customers account

 void applyPenalty(double balance, double penalty); 
// function to calculate the penatly for the customer 
 double calculatePenalty(); 
// deconstructor 
 ~SixMonthCD();
};

#endif 
