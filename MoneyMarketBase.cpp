#include "MoneyMarketBase.h"

MoneyMarketBase::MoneyMarketBase() 
    : monthlyInterest(1.25), maturityPenalty(0.0) {}

double MoneyMarketBase::withdrawalPenalty(double amount) const {
    return amount * (maturityPenalty / 100.0);
}

double MoneyMarketBase::getMonthlyInterest() const {
    return monthlyInterest;
}

double MoneyMarketBase::getMaturityPenalty() const {
    return maturityPenalty;
} 