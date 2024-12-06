#include "ThreeMonthCD.h"

/**
 * @brief Constructs a new Three Month CD account
 * @param initialBalance Initial deposit amount
 */
ThreeMonthCD::ThreeMonthCD(double initialBalance)
    : BankAccount(0, nullptr, "Three Month CD", "Active", initialBalance),
      CertificateOfDepositBase(initialBalance) {}

/**
 * @brief Calculates quarterly interest for the CD
 * @return Interest amount based on 1.5% APY
 */
double ThreeMonthCD::calculateInterest() const {
    return CertificateOfDepositBase::getBalance() * (0.015 / 4); // 1.5% APY, quarterly
}
