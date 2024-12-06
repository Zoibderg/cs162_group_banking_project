#include "CheckingAccount.h"

CheckingAccount::CheckingAccount()
    : BankAccount(0, nullptr, "Checking", "Active", 0.0),
      overdraft_limit(500.0) {}

CheckingAccount::CheckingAccount(double initialBalance)
    : BankAccount(0, nullptr, "Checking", "Active", initialBalance),
      overdraft_limit(500.0) {}

void CheckingAccount::check_overdraft() {
    if (getBalance() < 0 && std::abs(getBalance()) > overdraft_limit) {
        apply_overdraft_fee();
    }
}

void CheckingAccount::apply_overdraft_fee() {
    withdraw(35.0); // Standard overdraft fee
}
