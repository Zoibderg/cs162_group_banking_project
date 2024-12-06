#include "MoneyMarketBase.h"

/**
 * @brief Constructs a new Money Market Base object
 */
MoneyMarketBase::MoneyMarketBase() 
    : monthlyInterest(1.25), maturityPenalty(0.0) {}

/**
 * @brief Calculates withdrawal penalty
 * @param amount The withdrawal amount
 * @return The penalty amount based on maturity penalty rate
 */
double MoneyMarketBase::withdrawalPenalty(double amount) const {
    return amount * (maturityPenalty / 100.0);
}

/**
 * @brief Gets the monthly interest rate
 * @return The monthly interest rate as a percentage
 */
double MoneyMarketBase::getMonthlyInterest() const {
    return monthlyInterest;
}

/**
 * @brief Gets the maturity penalty rate
 * @return The maturity penalty rate as a percentage
 */
double MoneyMarketBase::getMaturityPenalty() const {
    return maturityPenalty;
} 