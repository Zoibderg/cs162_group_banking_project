#include "BankAccountContainer.h"
#include "Customer.h"
#include <algorithm>
#include <fstream>
#include <iostream> // For error messages

/**
 BankAccountContainer.cpp
  this implements the BankAccountContainer class, which manages a collection of customers and their accounts
  It does adding, finding, deleting, sorting, and saving/loading customer data
 
 Funcions
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
//customer: A pointer to the Customer object to be added.
void BankAccountContainer::addCustomer(Customer* customer)
{
    customers.push_back(customer);
}

//finds a customer by their unique ID.
//customerId: The ID of the customer to search for.
// returns a pointer to the found Customer object, or nullptr if not found.
Customer* BankAccountContainer::findCustomerById(int customerId)
{
    for (auto* customer : customers) //auto* makes sure the customer is deduced as a Customer*, adapts if customers' type changes in the future.
    {
        if (customer->getCustomerId() == customerId) // Fixed comparison
        {
            return customer;
        }
    }
    return nullptr;
}

//deletes a customer by their unique ID.
// customerId: The ID of the customer to delete.
//returns true if the customer was successfully deleted, false otherwise.
bool BankAccountContainer::deleteCustomer(int customerId)
{
    for (size_t i = 0; i < customers.size(); ++i) //step through
    {
        if (customers[i]->getCustomerId() == customerId)
        {
            delete customers[i]; //free memory for the customer
            customers.erase(customers.begin() + i); //remove the customer from the vector
            return true; //successful delete
        }
    }
    return false; //Customer not found
}

//Displays all customers and their associated accounts.
void BankAccountContainer::displayAllCustomers() const
{
    if (customers.empty()) //no customers :(
    {
        std::cout << "No customers to display.\n";
        return;
    }
    for (const auto* customer : customers)
    {
        customer->displayCustomer();
    }
}

//Sorts the customers alphabetically by their last names
//compareCustomersByLastName compares two Customer* objects by their last names.
bool compareCustomersByLastName(const Customer* a, const Customer* b)
{
    return a->getLastName() < b->getLastName();
}

void BankAccountContainer::sortCustomersByLastName()
{   //std::sort takes a comparison function (above) as its third parameter
    std::sort(customers.begin(), customers.end(), compareCustomersByLastName);
}

//Generates and returns the next unique account number.
//returns the next unique account number as an integer.
 */
int BankAccountContainer::getNextAccountNumber()
{
    return accountNumberGenerator++;
}

//Saves all customers and their accounts to a binary file
//filename: The name of the file to save the data to.
void BankAccountContainer::saveToFile(const std::string& filename) const
{
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error: Cannot open file " << filename << " for saving\n";
        return;
    }

    size_t customerCount = customers.size();
    //reinterpret_cast converts a pointer or reference of one type into another type
    //customerCount is likely an integer (size_t) that the # of customers to read from the file
    //&customerCount is the address of the variable customerCount. type is size_t*
    outFile.write(reinterpret_cast<const char*>(&customerCount), sizeof(customerCount));
    for (const auto* customer : customers)
    {
        customer->save(outFile); // Assumes Customer has a save method
    }
}

//Loads all customers and their accounts from a binary file.
//filename: The name of the file to load the data from.
void BankAccountContainer::loadFromFile(const std::string& filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile)
    {
        std::cerr << "Error: Cannot open file " << filename << " for loading\n";
        return;
    }

    //clear existing customers and free memory
    for (auto* customer : customers)
    {
        delete customer;
    }
    customers.clear();

    size_t customerCount;
    inFile.read(reinterpret_cast<char*>(&customerCount), sizeof(customerCount));
    for (size_t i = 0; i < customerCount; ++i)
    {
        Customer* customer = new Customer(); //Allocate memory for each customer
        customer->load(inFile);              //Load customer data
        customers.push_back(customer);
    }
}