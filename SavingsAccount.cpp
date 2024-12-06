#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double initialBalance)
    : BankAccount(0, nullptr, "Savings", "Active", initialBalance),
      interest_rate(0.025) {} // 2.5% interest rate

double SavingsAccount::calculate_interest() const {
    return getBalance() * interest_rate;
}

void SavingsAccount::apply_APR() {
    double interest = calculate_interest();
    deposit(interest);
}
