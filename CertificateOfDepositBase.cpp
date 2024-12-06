#include "CertificateOfDepositBase.h"

// Default constructor initializes balance to 0
CertificateOfDepositBase::CertificateOfDepositBase()
    : balance(0.0) {
}

// Constructor with initial balance parameter
CertificateOfDepositBase::CertificateOfDepositBase(double initialBalance)
    : balance(initialBalance) {
}

// Returns the current balance
double CertificateOfDepositBase::getBalance() const {
    return balance;
}

// Sets the balance to a new value
void CertificateOfDepositBase::setBalance(double newBalance) {
    balance = newBalance;
}
