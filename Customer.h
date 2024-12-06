#pragma once
#include <string>
#include <vector>
#include <random>
#include <memory>

class BankAccount; // Forward declaration

class Customer {
private:
    int customerId;
    std::string firstName;
    std::string lastName;
    std::vector<std::weak_ptr<BankAccount>> accounts;

    static int generateCustomerId() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(100000, 999999);
        return dis(gen);
    }

public:
    // Constructors
    Customer();
    Customer(const std::string& first, const std::string& last);
    
    // Destructor
    ~Customer();

    // Getters
    std::string getId() const { return std::to_string(customerId); }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getFullName() const { return firstName + " " + lastName; }

    // Account management
    void addAccount(std::shared_ptr<BankAccount> account);
    void updateAccount(int account_id);
    void displayAccounts() const;
};
