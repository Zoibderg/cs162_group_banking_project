#ifndef ONE_YEAR_CD_H
#define ONE_YEAR_CD_H

#include "CertificateOfDepositBase.h"
#include "BankAccount.h"

class OneYearCD : public BankAccount, public CertificateOfDepositBase {
public:
    OneYearCD(double initialBalance);
    double calculateInterest() const override;
};

#endif 
