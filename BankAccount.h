#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include <iostream>

// Forward declaration
class Customer;

class BankAccount {
private:
    int accountNumber;
    Customer* accountHolder;
    std::string accountType;
    std::string accountStatus;
    double balance;
    std::vector<std::string> transactions;

public:
    BankAccount(int accountNumber, Customer* holder, const std::string& type, 
                const std::string& status, double initialBalance);

    virtual ~BankAccount() = default;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    
    double getBalance() const;
    std::string getAccountHolder() const;
    std::string getAccountType() const;
    std::string getAccountStatus() const;
    int getAccountNumber() const;
    
    void setAccountNumber(int number);
    void setCustomer(Customer* customer);
    void generateStatement() const;
};

#endif
