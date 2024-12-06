#include "SixMonthCD.h"

SixMonthCD::SixMonthCD(double initialBalance)
    : BankAccount(0, nullptr, "Six Month CD", "Active", initialBalance),
      CertificateOfDepositBase(initialBalance) {}

double SixMonthCD::calculateInterest() const {
    return CertificateOfDepositBase::getBalance() * (0.02 / 2); // 2.0% APY, semi-annual
}
