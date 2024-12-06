#ifndef SIX_MONTH_CD_H
#define SIX_MONTH_CD_H

#include "CertificateOfDepositBase.h"
#include "BankAccount.h"

class SixMonthCD : public BankAccount, public CertificateOfDepositBase {
public:
    explicit SixMonthCD(double initialBalance);
    double calculateInterest() const override;
    using CertificateOfDepositBase::getBalance;
};

#endif 
