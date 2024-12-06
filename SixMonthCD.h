#ifndef Six_Month_CD_H 
#define Six_Month_CD_H 

/**              
 * Class for handling the Six Year CD operations
 */
class SixYearCD
{
public:
    /**
     * Default constructor
     */
    ThreeYearCD() = default;
/*
function for applying interest to customers account
*/
virtual void applyInterest(double apy, time_t duration); 
/*
function for applying penalty to customers account
*/ 
virtual void applyPenalty(double balance, double penalty); 
/**
* Virtual destructor
 */
    virtual ~SixYearCD() = default;

  
};

#endif 
