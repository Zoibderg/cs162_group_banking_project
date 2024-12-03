#pragma once
#include <string>
#include <vector>
#include "BankAccount.h"

class BankAccount; // Forward declaration to avoid circular dependency

/*
 * Represents a bank customer with personal details and multiple bank accounts.
 */
class Customer {
private:
    int customer_id; // Unique identifier for the customer
    std::string first_name; // Customer's first name
    std::string last_name; // Customer's last name
    std::vector<BankAccount*> accounts; // List of bank accounts associated with the customer

public:
    /*
     * Default constructor for the Customer class.
     * Initializes customer attributes to default values.
     */
    Customer();

    /*
     * Parameterized constructor for the Customer class.
     * id: Unique identifier for the customer.
     * firstName: Customer's first name.
     * lastName: Customer's last name.
     */
    Customer(int id, const std::string& firstName, const std::string& lastName);

    /*
     * Gets the customer's unique identifier.
     * Returns customer ID as an integer.
     */
    int getCustomerId() const;

    /*
     * Gets the customer's first name.
     * Returns first name as a string.
     */
    std::string getFirstName() const;

    /*
     * Gets the customer's last name.
     * Returns last name as a string.
     */
    std::string getLastName() const;

     /*
     * Gets the customer's full name.
     * Returns full name as a string.
     */
     std::string getFullName() const;


    /*
     * Adds a bank account to the customer's list of accounts.
     * account: Pointer to the bank account to be added.
     */
    void addAccount(BankAccount* account);

    /*
     * Updates an existing bank account by account ID.
     * Placeholder function for future implementation.
     * account_id: Unique identifier of the account to be updated.
     */
    void updateAccount(int account_id);

    /*
     * Displays information about all the bank accounts associated with the customer.
     */
    void displayAccounts() const;

    /*
     * Destructor for the Customer class.
     * Ensures that any resources are properly cleaned up.
     */
    ~Customer();
};
