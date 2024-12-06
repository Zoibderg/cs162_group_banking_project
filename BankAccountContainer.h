#pragma once

#include <algorithm>
#include <fstream>
#include <vector>
#include <memory>
#include "Customer.h"
#include "BankAccount.h"

/**
 * @class BankAccountContainer
 * @brief Container class for managing all bank accounts and customers
 * 
 * This class serves as the main data store for the banking system,
 * managing collections of customers and their associated accounts.
 * Provides functionality for account/customer management and persistence.
 */
class BankAccountContainer {
private:
    int accountNumberGenerator = 1000;  ///< Generator for unique account numbers
    std::vector<std::unique_ptr<Customer>> customers;  ///< Collection of all customers
    std::vector<std::unique_ptr<BankAccount>> accounts;  ///< Collection of all accounts

public:
    /**
     * @brief Adds a new customer to the system
     * @param customer Pointer to customer object to add
     */
    void addCustomer(Customer* customer);

    /**
     * @brief Finds a customer by their ID
     * @param customerId ID to search for
     * @return Pointer to found customer or nullptr if not found
     */
    Customer* findCustomerById(const std::string& customerId);

    /**
     * @brief Deletes a customer from the system
     * @param customerId ID of customer to delete
     * @return true if customer was deleted, false otherwise
     */
    bool deleteCustomer(const std::string& customerId);

    /**
     * @brief Deletes an account from the system
     * @param accountNumber Account number to delete
     * @return true if account was deleted, false otherwise
     */
    bool deleteAccount(int accountNumber);

    /**
     * @brief Finds an account by its number
     * @param accountNumber Account number to search for
     * @return Pointer to found account or nullptr if not found
     */
    BankAccount* findAccountByNumber(int accountNumber);

    /**
     * @brief Displays all customers in the system
     */
    void displayAllCustomers() const;

    /**
     * @brief Sorts customers by last name
     */
    void sortCustomersByLastName();

    /**
     * @brief Generates next available account number
     * @return New unique account number
     */
    int getNextAccountNumber();

    /**
     * @brief Saves system state to file
     * @param filename Name of file to save to
     */
    void saveToFile(const std::string& filename) const;

    /**
     * @brief Loads system state from file
     * @param filename Name of file to load from
     */
    void loadFromFile(const std::string& filename);

    /**
     * @brief Adds a new account to the system
     * @param account Pointer to account to add
     */
    void addAccount(BankAccount* account);

    /**
     * @brief Destructor
     */
    ~BankAccountContainer();

    // Display methods
    void displayAccountsSortedByBalance() const;
    void displayAccountsSortedByLastName() const;
    void displayAllAccounts() const;
};
