#ifndef THREE_MONTH_CD_H
#define THREE_MONTH_CD_H

#include "BankAccount.h"
#include "CertificateOfDepositBase.h"

/**
 * @class ThreeMonthCD
 * @brief Represents a 3-month Certificate of Deposit account
 * 
 * This class implements a short-term CD account with a three-month term.
 * It offers a lower interest rate than longer-term CDs but provides
 * quicker access to funds. Interest is calculated and applied quarterly.
 */
class ThreeMonthCD : public BankAccount, public CertificateOfDepositBase {
public:
    /**
     * @brief Constructor with initial balance
     * @param initialBalance Initial deposit amount
     * @details Creates a new 3-month CD with specified initial deposit
     */
    explicit ThreeMonthCD(double initialBalance);

    /**
     * @brief Calculates quarterly interest for the CD
     * @return Calculated interest amount based on 1.5% APY
     * @details Interest is calculated as (1.5% APY / 4) of current balance
     */
    double calculateInterest() const override;
};

#endif 
