#include <iostream>
#include "CertificateOfDepositBase.h"
#include "BankAccount.h"
#include "OneYearCD.h"

OneYearCD::OneYearCD(double initialBalance)
    : BankAccount(0, nullptr, "One Year CD", "Active", initialBalance),
      CertificateOfDepositBase(initialBalance) {
}

double OneYearCD::calculateInterest() const {
    // 2.5% APY for one year CD
    return getBalance() * 0.025;
}
