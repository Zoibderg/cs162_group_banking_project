#include "BankAccountContainer.h"
#include <algorithm>
#include <fstream>

/* Adds a new customer to the container. */
void BankAccountContainer::addCustomer(Customer* customer)
{
    customers.push_back(customer);
}

//* Finds a customer by their unique ID
Customer* BankAccountContainer::findCustomerById(const std::string& customerId)
{
    for (Customer* customer : customers)
    {
        if (customer->getId() == customerId)
        {
            return customer;
        }
    }
    return nullptr;
}

// Deletes a customer from the container by their unique ID
bool BankAccountContainer::deleteCustomer(const std::string& customerId)
{
    auto it = std::find_if(customers.begin(), customers.end(),
        [&customerId](Customer* c) { return c->getId() == customerId; });
    if (it != customers.end())
    {
        delete* it;
        customers.erase(it);
        return true;
    }
    return false;
}

// Displays all customers and their associated accounts
void BankAccountContainer::displayAllCustomers() const
{
    for (const Customer* customer : customers)
    {
        std::cout << "Customer ID: " << customer->getId() << std::endl;
        std::cout << "Name: " << customer->getFullName() << std::endl;
        customer->displayAccounts();
        std::cout << "------------------------\n";
    }
}

// Sorts all customers alphabetically by their last name
void BankAccountContainer::sortCustomersByLastName()
{
    std::sort(customers.begin(), customers.end(),
        [](Customer* a, Customer* b) { return a->getLastName() < b->getLastName(); });
}

// Generates the next unique account number
int BankAccountContainer::getNextAccountNumber()
{
    return accountNumberGenerator++;
}

// Saves all customers and their associated accounts to a binary file
void BankAccountContainer::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        // Implementation for saving to file
        file.close();
    }
}

//loads all customers and their associated accounts from a binary file
void BankAccountContainer::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        // loading from file
        file.close();
    }
}

//adds a new bank account
void BankAccountContainer::addAccount(BankAccount* account)
{
    accounts.push_back(account);
}

//Destructor to clean up dynamically allocated memory
BankAccountContainer::~BankAccountContainer()
{
    for (Customer* customer : customers)
    {
        delete customer;
    }
    for (BankAccount* account : accounts)
    {
        delete account;
    }
}
