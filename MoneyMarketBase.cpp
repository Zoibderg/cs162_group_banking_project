#include "MoneyMarketBase.h"

// Default constructor
MoneyMarketBase::MoneyMarketBase() = default;

// Calculate withdrawal penalty based on amount
double MoneyMarketBase::withdrawalPenalty(double amount) const {
    return amount * (maturityPenalty / 100.0);
}

// Get the monthly interest rate
double MoneyMarketBase::getMonthlyInterest() const {
    return monthlyInterest;
}

// Get the maturity penalty rate
double MoneyMarketBase::getMaturityPenalty() const {
    return maturityPenalty;
} 