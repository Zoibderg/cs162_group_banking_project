#include "MMDA.h"

// Default constructor
MMDA::MMDA() 
    : BankAccount(), handler(nullptr) {
}

// Constructor with initial balance
MMDA::MMDA(double initialBalance)
    : BankAccount(initialBalance), handler(nullptr) {
}

// Destructor
MMDA::~MMDA() {
    delete handler;
}

// Withdraw money from the account
void MMDA::withdraw(double amount) {
    if (amount <= getBalance()) {
        setBalance(getBalance() - amount);
    }
}

// Apply penalty to the account
void MMDA::applyPenalty() {
    double penalty = withdrawalPenalty(getBalance());
    setBalance(getBalance() - penalty);
} 