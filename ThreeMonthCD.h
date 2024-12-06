#ifndef THREE_MONTH_CD_H
#define THREE_MONTH_CD_H

#include "CertificateOfDepositBase.h"
#include "BankAccount.h"

class ThreeMonthCD : public BankAccount, public CertificateOfDepositBase {
public:
    ThreeMonthCD(double initialBalance);
    double calculateInterest() const override;
};

#endif 
