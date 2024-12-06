#include "OneYearCD.h"

OneYearCD::OneYearCD(double initialBalance)
    : BankAccount(0, nullptr, "One Year CD", "Active", initialBalance),
      CertificateOfDepositBase(initialBalance) {}

double OneYearCD::calculateInterest() const {
    return CertificateOfDepositBase::getBalance() * (0.025); // 2.5% APY
}
