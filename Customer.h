#pragma once
#include <string>
#include <vector>
#include <random>
#include "BankAccount.h"

class BankAccount; // Forward declaration to avoid circular dependency

/*
 * Represents a bank customer with personal details and multiple bank accounts.
 */
class Customer {
private:
    int customerId;  // 6-digit unique identifier for the customer
    std::string firstName;
    std::string lastName;
    std::vector<BankAccount*> accounts;

    /**
     * Generates a random 6-digit customer ID
     * @return A number between 100000 and 999999
     */
    static int generateCustomerId() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(100000, 999999);
        return dis(gen);
    }

public:
    /*
     * Default constructor for the Customer class.
     * Initializes customer attributes to default values.
     */
    Customer() : customerId(generateCustomerId()), firstName(""), lastName("") {}

    /*
     * Parameterized constructor for the Customer class.
     * firstName: Customer's first name.
     * lastName: Customer's last name.
     */
    Customer(const std::string& first, const std::string& last) 
        : customerId(generateCustomerId()), firstName(first), lastName(last) {}

    /*
     * Gets the customer's unique identifier.
     * Returns customer ID as a string.
     */
    std::string getId() const {
        return std::to_string(customerId);
    }

    /*
     * Gets the customer's first name.
     * Returns first name as a string.
     */
    std::string getFirstName() const { return firstName; }

    /*
     * Gets the customer's last name.
     * Returns last name as a string.
     */
    std::string getLastName() const { return lastName; }

    /*
     * Gets the customer's full name.
     * Returns full name as a string.
     */
    std::string getFullName() const { return firstName + " " + lastName; }

    /*
     * Adds a bank account to the customer's list of accounts.
     * account: Pointer to the bank account to be added.
     */
    void addAccount(BankAccount* account) { accounts.push_back(account); }

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
