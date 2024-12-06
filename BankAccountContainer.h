#pragma once

#include <algorithm> // For std::sort
#include <fstream>   // For file operations like save/load
#include <vector>    // For managing a dynamic list of customers
#include "Customer.h" // Provides the definition of Customer class
#include "BankAccount.h" // Provides the definition of BankAccount class

/*
 BankAccountContainer class is responsible for managing customers
 and their associated bank accounts.
 methods or adding, searching, deleting, sorting customers
 saving and loading customer data to/from files.
 Initial by Jordan B
 */
class BankAccountContainer
{
private:
    int accountNumberGenerator = 1000; // Tracks the next unique account number
    std::vector<Customer*> customers; // List of pointers to all customers in the system
    std::vector<BankAccount*> accounts; // List of pointers to all bank accounts in the system

public:
    /* Adds a new customer to the container.
       Manages customers in the system by pushing
       the  Customer pointer to the internal vector
       takes customer A pointer to the Customer object to be added
     */
    void addCustomer(Customer* customer);

    /* Finds a customer by their unique ID.
       goes through the vector of customers to locate the one matching the provided ID
       takes customerId: unique ID of the customer to find
       returns A pointer to the found Customer object, or nullptr if not found
     */
    Customer* findCustomerById(const std::string& customerId);

    /* Deletes a customer from the container by their unique ID.
       Searches for the customer in the vector, removes it from memory
       @param customerId: unique ID of the customer to delete
       @return True if the customer was successfully deleted, false if not
     */
    bool deleteCustomer(const std::string& customerId);

    /* Displays all customers and their accounts
       goes through the vector and prints each customer's details */
    void displayAllCustomers() const;

    /* Sorts all customers alphabetically by their last name.
       Uses the std::sort algorithm with a custom comparator  */
    void sortCustomersByLastName();

    /* Generates the next unique account number.
       Each time this is called, it increments the generator so we have unique values.
       returns The next available account number.
     */
    int getNextAccountNumber();

    // Saves all customers and their associated accounts to a binary file.
    // takes filename
    void saveToFile(const std::string& filename) const;

    // Loads all customers and their associated accounts from a binary file.
    // takes filename
    void loadFromFile(const std::string& filename);

    /* Adds a new bank account to the system.
       takes a pointer to the BankAccount object to be added.
    */
    void addAccount(BankAccount* account);

    /* Destructor for BankAccountContainer.
       kills all  allocated Customer and BankAccount objects to avoid memory leaks. */
    ~BankAccountContainer();
};
