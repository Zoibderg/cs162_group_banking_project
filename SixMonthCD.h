#ifndef SIX_MONTH_CD_H
#define SIX_MONTH_CD_H

#include "BankAccount.h"
#include "CertificateOfDepositBase.h"

/**
 * @class SixMonthCD
 * @brief Represents a 6-month Certificate of Deposit account
 * 
 * This class implements a medium-term CD account with a six-month term.
 * It offers a higher interest rate than three-month CDs but lower than
 * one-year CDs. Interest is calculated and applied semi-annually.
 */
class SixMonthCD : public BankAccount, public CertificateOfDepositBase {
public:
    /**
     * @brief Constructor with initial balance
     * @param initialBalance Initial deposit amount
     * @details Creates a new 6-month CD with specified initial deposit
     */
    explicit SixMonthCD(double initialBalance);

    /**
     * @brief Calculates semi-annual interest for the CD
     * @return Calculated interest amount based on 2.0% APY
     * @details Interest is calculated as (2.0% APY / 2) of current balance
     */
    double calculateInterest() const override;
};

#endif 
