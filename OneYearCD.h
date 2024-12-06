#ifndef ONE_YEAR_CD_H
#define ONE_YEAR_CD_H

#include "BankAccount.h"
#include "CertificateOfDepositBase.h"

/**
 * @class OneYearCD
 * @brief Represents a 1-year Certificate of Deposit account
 * 
 * This class implements a CD account with a one-year term and
 * specific interest rate calculations. Offers higher interest
 * rate than shorter-term CDs.
 */
class OneYearCD : public BankAccount, public CertificateOfDepositBase {
public:
    /**
     * @brief Constructor with initial balance
     * @param initialBalance Initial deposit amount
     */
    explicit OneYearCD(double initialBalance);

    /**
     * @brief Calculates annual interest for the CD
     * @return Calculated interest amount (2.5% APY)
     */
    double calculateInterest() const override;
};

#endif 
