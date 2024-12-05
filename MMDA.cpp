#include "MMDA.h"

// Default constructor
MMDA::MMDA() 
    : balance(0.0), handler(nullptr) {
}

// Constructor with initial balance
MMDA::MMDA(double initialBalance)
    : balance(initialBalance), handler(nullptr) {
}

// Destructor
MMDA::~MMDA() {
    delete handler;
}

// Get the current balance
double MMDA::getBalance() const {
    return balance;
}

// Set the account balance
void MMDA::setBalance(double amount) {
    balance = amount;
}

// Withdraw money from the account
void MMDA::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
}

// Apply penalty to the account
void MMDA::applyPenalty() {
    double penalty = withdrawalPenalty(balance);
    balance -= penalty;
} 