#ifndef Three_Month_CD_H 
#define Three_Month_CD_H 

/**              
 * Class for handling the Three Year CD operations
 */
class ThreeYearCD
{
public:
time_t duration;
double apy;
double penalty; 
    /**
     * Default constructor
     */
    ThreeYearCD() = default;
virtual void applyInterest(double apy, time_t duration); 

virtual void applyPenalty(double balance, double penalty); 

void calculatePenalty() 

void calculateInterest()

};

#endif 
