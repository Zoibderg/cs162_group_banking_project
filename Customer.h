#pragma once
#include <string>
#include <vector>
#include <random>
#include <memory>

class BankAccount; // Forward declaration

/**
 * @class Customer
 * @brief Represents a bank customer with associated accounts
 * 
 * This class manages customer information and maintains a list of their
 * associated bank accounts using weak pointers to prevent circular references.
 */
class Customer {
private:
    int customerId;                                    ///< Unique identifier for the customer
    std::string firstName;                            ///< Customer's first name
    std::string lastName;                             ///< Customer's last name
    std::vector<std::weak_ptr<BankAccount>> accounts; ///< List of customer's accounts

    /**
     * @brief Generates a unique customer ID
     * @return Random 6-digit customer ID
     */
    static int generateCustomerId() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(100000, 999999);
        return dis(gen);
    }

public:
    /**
     * @brief Default constructor
     */
    Customer();

    /**
     * @brief Constructor with name parameters
     * @param first Customer's first name
     * @param last Customer's last name
     */
    Customer(const std::string& first, const std::string& last);
    
    /**
     * @brief Destructor
     */
    ~Customer();

    // Getters
    std::string getId() const { return std::to_string(customerId); }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getFullName() const { return firstName + " " + lastName; }

    /**
     * @brief Adds a new account to the customer's portfolio
     * @param account Shared pointer to the account to add
     */
    void addAccount(std::shared_ptr<BankAccount> account);

    /**
     * @brief Updates information for a specific account
     * @param account_id ID of the account to update
     */
    void updateAccount(int account_id);

    /**
     * @brief Displays all accounts owned by the customer
     */
    void displayAccounts() const;
};
