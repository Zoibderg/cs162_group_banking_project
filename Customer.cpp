#include "Customer.h"
#include "BankAccount.h"
#include <iostream>

Customer::Customer() 
    : customerId(generateCustomerId()), firstName(""), lastName("") {}

Customer::Customer(const std::string& first, const std::string& last)
    : customerId(generateCustomerId()), firstName(first), lastName(last) {}

Customer::~Customer() {
    accounts.clear();
}

void Customer::addAccount(std::shared_ptr<BankAccount> account) {
    accounts.push_back(std::weak_ptr<BankAccount>(account));
}

void Customer::updateAccount(int account_id) {
    // Implementation can be added later as needed
}

void Customer::displayAccounts() const {
    for (const std::weak_ptr<BankAccount>& weakAccount : accounts) {
        if (auto sharedAccount = weakAccount.lock()) {
            sharedAccount->generateStatement();
            std::cout << "------------------------\n";
        }
    }
}
