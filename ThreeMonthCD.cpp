#include "ThreeMonthCD.h"

ThreeMonthCD::ThreeMonthCD(double initialBalance)
    : BankAccount(0, nullptr, "Three Month CD", "Active", initialBalance),
      CertificateOfDepositBase(initialBalance) {}

double ThreeMonthCD::calculateInterest() const {
    return CertificateOfDepositBase::getBalance() * (0.015 / 4); // 1.5% APY, quarterly
}
