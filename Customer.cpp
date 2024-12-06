#include "Customer.h"
#include "BankAccount.h"
#include <iostream>

Customer::Customer() 
    : customerId(generateCustomerId()), firstName(""), lastName("") {}

Customer::Customer(const std::string& first, const std::string& last)
    : customerId(generateCustomerId()), firstName(first), lastName(last) {}

Customer::~Customer() {
    for (auto* account : accounts) {
        delete account;
    }
    accounts.clear();
}

void Customer::addAccount(BankAccount* account) {
    accounts.push_back(account);
}

void Customer::updateAccount(int account_id) {
    // Implementation can be added later as needed
}

void Customer::displayAccounts() const {
    for (const auto* account : accounts) {
        account->generateStatement();
        std::cout << "------------------------\n";
    }
}
