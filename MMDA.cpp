#include "MMDA.h"

// Default constructor
MMDA::MMDA() 
    : BankAccount(0, nullptr, "MMDA", "Active", 0.0), handler(nullptr) {
}

// Constructor with initial balance
MMDA::MMDA(double initialBalance)
    : BankAccount(0, nullptr, "MMDA", "Active", initialBalance), handler(nullptr) {
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

// Set the balance of the account
void MMDA::setBalance(double newBalance) {
    if (newBalance >= 0) {
        BankAccount::withdraw(getBalance());
        BankAccount::deposit(newBalance);
    }
}

// Get the balance of the account
double MMDA::getBalance() const {
    return BankAccount::getBalance();
} 