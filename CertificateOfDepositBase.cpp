#include "CertificateOfDepositBase.h"

CertificateOfDepositBase::CertificateOfDepositBase()
    : balance(0.0) {}

CertificateOfDepositBase::CertificateOfDepositBase(double initialBalance)
    : balance(initialBalance) {}

double CertificateOfDepositBase::getBalance() const {
    return balance;
}

void CertificateOfDepositBase::setBalance(double newBalance) {
    balance = newBalance;
}
