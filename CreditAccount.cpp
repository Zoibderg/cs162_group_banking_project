#include "CreditAccount.h"

CreditAccount::CreditAccount(double initialBalance)
    : BankAccount(0, nullptr, "Credit", "Active", initialBalance),
      credit_limit(5000.0), APR(0.1995), min_payment(25.0) {}

double CreditAccount::calculate_minimum_payment() const {
    return std::max(min_payment, getBalance() * 0.02); // 2% of balance or $25, whichever is greater
}

bool CreditAccount::check_credit_limit() const {
    return std::abs(getBalance()) <= credit_limit;
}
