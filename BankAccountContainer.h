#pragma once
#include <vector>
#include <string>

// declaration of the Customer class for now, we will probably end up with a customer.h?
 */
class Customer;

/**
 class is for managing all customers and their associated accounts.
 used for adding, finding, deleting, and sorting customers,
 as well as saving and loading customer data to/from a file.
 */
class BankAccountContainer
{
private:
    int accountNumberGenerator = 1000; //keeps track of the next unique account number to assign
    std::vector<Customer*> customers; //stores all the customers in the system as pointers

public:
    //Adds a new customer to the list of customers.
    // takes a customer: A pointer to the Customer object to be added.
    void addCustomer(Customer* customer);

    //Finds a customer by their unique ID.
    //customerId: The ID of the customer to search for.
    // returns a pointer to the found Customer object, or nullptr if not found.
  
    Customer* findCustomerById(int customerId);

     // deletes a customer by their unique ID.
     //customerId: The ID of the customer to delete.
     //returns True if the customer was successfully deleted, false otherwise.
     
    bool deleteCustomer(int customerId);

    //displays all customers and their accounts in the system.
    void displayAllCustomers() const;

    //sorts the customers alphabetically by their last names.
    void sortCustomersByLastName();

    
    //generates and returns the next unique account number.
    // returns the next unique account number as an integer.
    int getNextAccountNumber();

    //Saves all customers and their accounts to a binary file.
    //filename: The name of the file to save the data to.
    void saveToFile(const std::string& filename) const;

    //Loads all customers and their accounts from a binary file.
    //filename: The name of the file to load the data from.
    void loadFromFile(const std::string& filename);
};
