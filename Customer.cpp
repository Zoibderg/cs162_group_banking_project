#include "Customer.h"
#include "BankAccount.h"
#include <iostream>
#include <fstream>


// Default Constructor
Customer::Customer() : customerId(generateCustomerId()), firstName(""), lastName("") {}

// Overloaded Constructor
Customer::Customer(const std::string& first, const std::string& last)
    : customerId(generateCustomerId()), firstName(first), lastName(last) {
}

// Getters
int Customer::getCustomerId() const {
    return customerId;
}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getLastName() const {
    return lastName;
}

std::string Customer::getFullName() const {
    return firstName + " " + lastName;
}

// Account Management
void Customer::addAccount(BankAccount* account) {
    accounts.push_back(account);
}

void Customer::updateAccount(int account_id) {
    std::cout << "Update Account functionality is not yet implemented." << std::endl;
}

// Display all accounts associated with the customer
void Customer::displayAccounts() const {
    std::cout << "Customer: " << getFullName() << " (ID: " << customerId << ")" << std::endl;
    for (const auto* account : accounts) {
        account->generateStatement();
    }
}

// Display customer details
void Customer::displayCustomer() const {
    std::cout << "Customer ID: " << customerId
        << ", Name: " << getFullName() << std::endl;
}

// Save customer data to file
void Customer::save(std::ofstream& outFile) const {
    size_t firstNameSize = firstName.size();
    size_t lastNameSize = lastName.size();

    outFile.write(reinterpret_cast<const char*>(&customerId), sizeof(customerId));
    outFile.write(reinterpret_cast<const char*>(&firstNameSize), sizeof(firstNameSize));
    outFile.write(reinterpret_cast<const char*>(&lastNameSize), sizeof(lastNameSize));
    outFile.write(firstName.c_str(), firstNameSize);
    outFile.write(lastName.c_str(), lastNameSize);
}

// Load customer data from file
void Customer::load(std::ifstream& inFile) {
    size_t firstNameSize = 0, lastNameSize = 0;

    // Read the ID and sizes
    inFile.read(reinterpret_cast<char*>(&customerId), sizeof(customerId));
    inFile.read(reinterpret_cast<char*>(&firstNameSize), sizeof(firstNameSize));
    inFile.read(reinterpret_cast<char*>(&lastNameSize), sizeof(lastNameSize));

    // Resize and read strings
    firstName.resize(firstNameSize);
    lastName.resize(lastNameSize);
    inFile.read(&firstName[0], firstNameSize);
    inFile.read(&lastName[0], lastNameSize);
}

// Destructor
Customer::~Customer() {
    for (auto* account : accounts) {
        delete account;
    }
    accounts.clear();
}
