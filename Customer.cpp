#include "Customer.h"
#include "BankAccount.h"
#include <iostream>

/**
 * @brief Default constructor
 * @details Creates a customer with empty name and generates unique ID
 */
Customer::Customer() 
    : customerId(generateCustomerId()), firstName(""), lastName("") {}

/**
 * @brief Constructor with name parameters
 * @param first Customer's first name
 * @param last Customer's last name
 * @details Creates a customer with specified name and generates unique ID
 */
Customer::Customer(const std::string& first, const std::string& last)
    : customerId(generateCustomerId()), firstName(first), lastName(last) {}

/**
 * @brief Destructor
 * @details Cleans up customer data and clears account references
 */
Customer::~Customer() {
    accounts.clear();
}

/**
 * @brief Adds a new account to customer's portfolio
 * @param account Shared pointer to the account to be added
 * @details Creates a weak reference to the account to prevent circular references
 */
void Customer::addAccount(std::shared_ptr<BankAccount> account) {
    accounts.push_back(std::weak_ptr<BankAccount>(account));
}

/**
 * @brief Updates information for a specific account
 * @param account_id ID of the account to update
 * @details Currently a placeholder for future implementation
 */
void Customer::updateAccount(int account_id) {
    // Implementation can be added later as needed
}

/**
 * @brief Displays all accounts owned by the customer
 * @details Generates statements for all active accounts
 */
void Customer::displayAccounts() const {
    for (const std::weak_ptr<BankAccount>& weakAccount : accounts) {
        if (auto sharedAccount = weakAccount.lock()) {
            sharedAccount->generateStatement();
            std::cout << "------------------------\n";
        }
    }
}
