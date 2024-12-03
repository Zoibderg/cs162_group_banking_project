#include "Customer.h"
#include <iostream>

// Default Constructor
// Initializes a customer with default values (ID = 0, empty names).
Customer::Customer() : customer_id(0), first_name(""), last_name("") {}

// Overloaded Constructor
// Initializes a customer with specific ID, first name, and last name.
// @param id: Unique identifier for the customer.
// @param firstName: Customer's first name.
// @param lastName: Customer's last name.
Customer::Customer(int id, const std::string& firstName, const std::string& lastName)
    : customer_id(id), first_name(firstName), last_name(lastName) {}

// Getters
// Returns the customer ID.
int Customer::getCustomerId() const {
    return customer_id;
}

// Returns the first name of the customer.
std::string Customer::getFirstName() const {
    return first_name;
}

// Returns the last name of the customer.
std::string Customer::getLastName() const {
    return last_name;
}

// Returns the full name of the customer.
std::string Customer::getFullName() const {
    return first_name + " " + last_name;
}

// Account Management

// Adds a bank account to the customer's list of accounts.
// @param account: Pointer to a BankAccount object to be added.
void Customer::addAccount(BankAccount* account) {
    accounts.push_back(account);
}

// Updates a bank account with the given account ID.
// This is a placeholder function that currently outputs a message indicating it's not implemented.
// @param account_id: The unique identifier for the account to be updated.
void Customer::updateAccount(int account_id) {
    // Placeholder for updating an account based on ID (e.g., modifying account details)
    std::cout << "Update Account functionality is not yet implemented." << std::endl;
}

// Displays all accounts associated with the customer.
// Outputs the customer details and calls the display function for each associated account.
void Customer::displayAccounts() const {
    std::cout << "Customer: " << getFullName() << " (ID: " << customer_id << ")" << std::endl;
    for (const auto* account : accounts) {
        account->generateStatement(); // BankAccount has a generateStatement() function
    }
}

// Destructor to handle account pointers
// Iterates through all accounts and deletes the dynamically allocated memory.
Customer::~Customer() {
    for (auto* account : accounts) {
        delete account;
    }
    accounts.clear();
}
