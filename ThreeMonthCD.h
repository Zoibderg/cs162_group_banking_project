#ifndef THREE_MONTH_CD_H
#define THREE_MONTH_CD_H

#include "CertificateOfDepositBase.h"
#include "BankAccount.h"

class ThreeMonthCD : public BankAccount, public CertificateOfDepositBase {
public:
    explicit ThreeMonthCD(double initialBalance);
    double calculateInterest() const override;
    using CertificateOfDepositBase::getBalance;
};

#endif 
