#ifndef Three_Year-CD_H 
#define Three_Year_CD_H 

/**              
 * Class for handling the Three Year CD operations
 */
class ThreeYearCD
{
public:
    /**
     * Default constructor
     */
    ThreeYearCD() = default;
virtual void applyInterest(double apy, time_t duration); 

virtual void applyPenalty(double balance, double penalty); 
    /**
     * Virtual destructor
     */
    virtual ~ThreeYearCD() = default;

  
};

#endif 
