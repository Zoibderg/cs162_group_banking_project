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
    // Default constructor
    Customer();

    // Parameterized constructor
    Customer(const std::string& first, const std::string& last);

    // Getters for customer details
    int getCustomerId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;

    // Account management
    void addAccount(BankAccount* account);
    void updateAccount(int account_id);

    // Display all accounts for the customer
    void displayAccounts() const;

    // Display customer details (name and ID)
    void displayCustomer() const;

    // Save and load customer details
    void save(std::ofstream& outFile) const;
    void load(std::ifstream& inFile);

    // Destructor to handle cleanup
    ~Customer();
};
