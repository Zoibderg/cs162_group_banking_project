#include "BankAccount.h"
#include "Customer.h"

BankAccount::BankAccount(int accountNumber, Customer* holder, const std::string& type,
                        const std::string& status, double initialBalance)
    : accountNumber(accountNumber), accountHolder(holder), accountType(type),
      accountStatus(status), balance(initialBalance) {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactions.push_back("Deposit: $" + std::to_string(amount));
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactions.push_back("Withdrawal: $" + std::to_string(amount));
    }
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getAccountHolder() const {
    return accountHolder ? accountHolder->getFullName() : "No holder";
}

std::string BankAccount::getAccountType() const {
    return accountType;
}

std::string BankAccount::getAccountStatus() const {
    return accountStatus;
}

int BankAccount::getAccountNumber() const {
    return accountNumber;
}

void BankAccount::setAccountNumber(int number) {
    accountNumber = number;
}

void BankAccount::setCustomer(Customer* customer) {
    accountHolder = customer;
}

void BankAccount::generateStatement() const {
    std::cout << "Account Holder: " << getAccountHolder() << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Type: " << accountType << std::endl;
    std::cout << "Account Status: " << accountStatus << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    std::cout << "Transactions: " << std::endl;
    for (const auto& transaction : transactions) {
        std::cout << transaction << std::endl;
    }
}

