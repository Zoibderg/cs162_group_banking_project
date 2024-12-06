#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Customer.h"

class BankAccount {
private:
    int accountNumber;
    Customer* accountHolder;
    double balance;

public:
    BankAccount() : accountNumber(0), accountHolder(nullptr), balance(0.0) {}
    explicit BankAccount(double initialBalance) 
        : accountNumber(0), accountHolder(nullptr), balance(initialBalance) {}
    virtual ~BankAccount() = default;

    void setAccountNumber(int number) { accountNumber = number; }
    int getAccountNumber() const { return accountNumber; }
    
    void setCustomer(Customer* customer) { accountHolder = customer; }
    Customer* getCustomer() const { return accountHolder; }
    
    double getBalance() const { return balance; }
    void setBalance(double newBalance) { balance = newBalance; }
};

#endif
