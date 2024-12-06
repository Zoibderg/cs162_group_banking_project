#include "BankAccountContainer.h"
#include <algorithm>
#include <fstream>
#include <iostream> // For error messages

/**
 BankAccountContainer.cpp
  this implements the BankAccountContainer class, which manages a collection of customers and their accounts
  It does adding, finding, deleting, sorting, and saving/loading customer data
 
 functions
 void addCustomer(Customer* customer)
 - Adds a new customer to the container
 - parameters:  customer: A pointer to the Customer object to be added
 
 Customer* findCustomerById(int customerId)
 - Finds a customer by their unique ID.
 - parameters: customerId: The ID of the customer to search for
 - returns a pointer to the found Customer object, or nullptr if not found
 
 bool deleteCustomer(int customerId)
 - Deletes a customer by their unique ID
 - parameters: customerId: The ID of the customer to delete
 - returns true if the customer was successfully deleted, false otherwise
 
 void displayAllCustomers() const
  - displays all customers and their associated accounts

  void sortCustomersByLastName()
  - sorts customers alphabetically by their last names
 
 int getNextAccountNumber()
 - Generates and returns the next unique account number
 - returns the next unique account number as an integer
 
 void saveToFile(const std::string& filename) const
 - saves all customers and their accounts to a binary file.
 - parameters: filename to use

 void loadFromFile(const std::string& filename)
 - loads all customers and their accounts from a binary file.
 - parameters: filename to load
 */


//Adds a new customer to the system.
//pushes the given customer object into the customers vector
//takes customer Pointer to the customer object to add
void BankAccountContainer::addCustomer(Customer * customer)
{
    customers.push_back(customer);
}

//finds a customer by their unique ID
// goes through the customers vector and compares customer IDs
// takes ustomerId" The unique ID of the customer to find.
// returns a pointer to the found customer, or nullptr if not found
Customer* BankAccountContainer::findCustomerById(int customerId)
{
    for (auto* customer : customers)
    {
        if (customer->getCustomerId() == customerId)
        {
            return customer;
        }
    }
    return nullptr;
}

//Deletes a customer by ID
 // Searches for the customer, deletes the object from memory, and removes it from the vector
 //takes customerId
 //returns True if the customer was successfully deleted, false otherwise.
 bool BankAccountContainer::deleteCustomer(int customerId)
{
    for (size_t i = 0; i < customers.size(); ++i)
    {
        if (customers[i]->getCustomerId() == customerId)
        {
            delete customers[i];
            customers.erase(customers.begin() + i);
            return true;
        }
    }
    return false;
}

// Displays all customers and their associated accounts.
 //Loops through each customer and calls their displayCustomer() method.
 void BankAccountContainer::displayAllCustomers() const
{
    if (customers.empty())
    {
        std::cout << "No customers to display.\n";
        return;
    }
    for (const auto* customer : customers)
    {
        customer->displayCustomer(); // Display the details of each customer
    }
}

// sorts customers alphabetically by last name.
 /* used as a helper for std::sort.
 * param a Pointer to the first customer.
 * param b Pointer to the second customer.
 * returns True if the first customer's last name comes before the second.
 */
bool compareCustomersByLastName(const Customer* a, const Customer* b)
{
    return a->getLastName() < b->getLastName();
}

/**
 * Sorts customers alphabetically by last name.
 * Uses the compareCustomersByLastName function to perform the sorting.
 */
void BankAccountContainer::sortCustomersByLastName()
{
    std::sort(customers.begin(), customers.end(), compareCustomersByLastName);
}

/**
 * Generates the next unique account number.
 * Increments the accountNumberGenerator counter and returns the new number.
 * returns The next unique account number.
 */
int BankAccountContainer::getNextAccountNumber()
{
    return accountNumberGenerator++;
}

/*
 * Saves all customers and their accounts to a binary file.
 * Writes the number of customers, followed by serialized customer data.
 * takes filename
 */
void BankAccountContainer::saveToFile(const std::string& filename) const
{
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error: Cannot open file " << filename << " for saving\n";
        return;
    }

    size_t customerCount = customers.size();
    outFile.write(reinterpret_cast<const char*>(&customerCount), sizeof(customerCount));
    for (const auto* customer : customers)
    {
        customer->save(outFile); // Serialize each customer into the file
    }
}

/*Loads all customers and their accounts from a binary file.
 * Reads the customer count, then deserializes customer data from the file.
 * takes filename
 */
void BankAccountContainer::loadFromFile(const std::string& filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile)
    {
        std::cerr << "Error: Cannot open file " << filename << " for loading\n";
        return;
    }

    // Cleanup any existing customer data
    for (auto* customer : customers)
    {
        delete customer;
    }
    customers.clear();

    size_t customerCount;
    inFile.read(reinterpret_cast<char*>(&customerCount), sizeof(customerCount));
    for (size_t i = 0; i < customerCount; ++i)
    {
        Customer* customer = new Customer();
        customer->load(inFile); // Deserialize customer from the file
        customers.push_back(customer);
    }
}

/* Destructor to clean up dynamically allocated memory.
 * Deletes all customers and accounts stored in their respective vectors. */
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