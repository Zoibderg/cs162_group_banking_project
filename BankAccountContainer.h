#pragma once
#include <vector>
#include <string>
#include "Customer.h"
#include "BankAccount.h"

/**
 * Manages all customers and their associated accounts.
 * Provides functionality for adding, finding, deleting, and sorting customers,
 * as well as saving and loading customer data to/from a file.
 */
class BankAccountContainer
{
private:
    int accountNumberGenerator = 1000; // Tracks the next unique account number
    std::vector<Customer*> customers; // Stores all customers
    std::vector<BankAccount*> accounts; // Stores all bank accounts

public:
    /**
     * Adds a new customer to the system.
     * @param customer Pointer to the customer object to add.
     */
    void addCustomer(Customer* customer);

    /**
     * Finds a customer by their unique ID.
     * @param customerId The unique ID of the customer to find.
     * @return Pointer to the found customer, or nullptr if not found.
     */
    Customer* findCustomerById(int customerId);

    /**
     * Deletes a customer by their unique ID.
     * @param customerId The unique ID of the customer to delete.
     * @return True if the customer was successfully deleted, false otherwise.
     */
    bool deleteCustomer(int customerId);

    /**
     * Displays all customers and their associated accounts.
     */
    void displayAllCustomers() const;

    /**
     * Sorts customers alphabetically by their last name.
     */
    void sortCustomersByLastName();

    /**
     * Generates and returns the next unique account number.
     * @return The next unique account number.
     */
    int getNextAccountNumber();

    /**
     * Saves all customers and their accounts to a binary file.
     * @param filename The name of the file to save to.
     */
    void saveToFile(const std::string& filename) const;

    /**
     * Loads all customers and their accounts from a binary file.
     * @param filename The name of the file to load from.
     */
    void loadFromFile(const std::string& filename);

    /**
     * Adds a new bank account to the
