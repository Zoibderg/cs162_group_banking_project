#include "SixMonthCD.h"

/**
 * @brief Constructs a new Six Month CD account
 * @param initialBalance Initial deposit amount
 */
SixMonthCD::SixMonthCD(double initialBalance)
    : BankAccount(0, nullptr, "Six Month CD", "Active", initialBalance),
      CertificateOfDepositBase(initialBalance) {}

/**
 * @brief Calculates semi-annual interest for the CD
 * @return Interest amount based on 2.0% APY
 */
double SixMonthCD::calculateInterest() const {
    return CertificateOfDepositBase::getBalance() * (0.02 / 2); // 2.0% APY, semi-annual
}
