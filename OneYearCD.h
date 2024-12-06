#ifndef One_Year_CD_H 
#define One_Year_CD_H 

/**              
 * Class for handling the Three Year CD operations
 */
class OneYearCD
{
public:
    /**
     * Default constructor
     */
    OneYearCD() = default;
/*
function that applies interest to the customers account 
*/

virtual void applyInterest(double apy, time_t duration); 

/*
function that applies a penalty to the customers account 
*/

virtual void applyPenalty(double balance, double penalty); 
/**
* Virtual destructor
*/
    virtual ~OneYearCD() = default;

  
};

#endif 
