#include "OneYearCD.h"

/**
 * @brief Constructs a new One Year CD account
 * @param initialBalance Initial deposit amount
 * @details Initializes a CD with one-year term and specified balance
 */
OneYearCD::OneYearCD(double initialBalance)
    : BankAccount(0, nullptr, "One Year CD", "Active", initialBalance),
      CertificateOfDepositBase(initialBalance) {}

/**
 * @brief Calculates annual interest for the CD
 * @return Interest amount based on 2.5% APY
 * @details Annual interest is calculated once per year at the full rate
 */
double OneYearCD::calculateInterest() const {
    return CertificateOfDepositBase::getBalance() * 0.025; // 2.5% APY
}
