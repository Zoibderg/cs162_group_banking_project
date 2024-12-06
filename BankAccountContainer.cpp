#include "BankAccountContainer.h"
#include <algorithm>
#include <fstream>

void BankAccountContainer::addCustomer(Customer* customer) {
    customers.push_back(customer);
}

Customer* BankAccountContainer::findCustomerById(const std::string& customerId) {
    for (Customer* customer : customers) {
        if (customer->getId() == customerId) {
            return customer;
        }
    }
    return nullptr;
}

bool BankAccountContainer::deleteCustomer(const std::string& customerId) {
    auto it = std::find_if(customers.begin(), customers.end(),
                          [&customerId](Customer* c) { return c->getId() == customerId; });
    if (it != customers.end()) {
        delete *it;
        customers.erase(it);
        return true;
    }
    return false;
}

void BankAccountContainer::displayAllCustomers() const {
    for (const Customer* customer : customers) {
        std::cout << "Customer ID: " << customer->getId() << std::endl;
        std::cout << "Name: " << customer->getFullName() << std::endl;
        customer->displayAccounts();
        std::cout << "------------------------\n";
    }
}

void BankAccountContainer::sortCustomersByLastName() {
    std::sort(customers.begin(), customers.end(),
              [](Customer* a, Customer* b) { return a->getLastName() < b->getLastName(); });
}

int BankAccountContainer::getNextAccountNumber() {
    return accountNumberGenerator++;
}

void BankAccountContainer::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        // Implementation for saving to file
        file.close();
    }
}

void BankAccountContainer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        // Implementation for loading from file
        file.close();
    }
}