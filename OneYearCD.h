#ifndef One_Year_CD_H 
#define One_Year_CD_H 

/**              
 * Class for handling the Three Year CD operations
 */
class OneYearCD
{
public:
time_t duration;
double apy;
double penalty; 
    OneYearCD() = default;
/*
function that applies interest to the customers account 
*/

void applyInterest(double apy, time_t duration); 

/*
function that applies a penalty to the customers account 
*/

void applyPenalty(double balance, double penalty); 
// function for calculating the penalty for the customer 
double calculatePenalty();
// function for calculating the interest for the customer 
double calculateInterest(); 

 // destructor

    ~OneYearCD();

  
};

#endif 
