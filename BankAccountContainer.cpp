#include "BankAccountContainer.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "MMDA.h"
#include "CreditAccount.h"
#include "OneYearCD.h"
#include "ThreeMonthCD.h"
#include "SixMonthCD.h"
#include <algorithm>
#include <fstream>
#include <iomanip>

/* Adds a new customer to the container. */
void BankAccountContainer::addCustomer(Customer* customer)
{
    customers.push_back(std::unique_ptr<Customer>(customer));
}

//* Finds a customer by their unique ID
Customer* BankAccountContainer::findCustomerById(const std::string& customerId)
{
    for (const auto& customer : customers)
    {
        if (customer->getId() == customerId)
        {
            return customer.get();
        }
    }
    return nullptr;
}

// Deletes a customer from the container by their unique ID
bool BankAccountContainer::deleteCustomer(const std::string& customerId)
{
    auto it = std::find_if(customers.begin(), customers.end(),
        [&customerId](const std::unique_ptr<Customer>& c) { 
            return c->getId() == customerId; 
        });
    if (it != customers.end())
    {
        customers.erase(it);  // unique_ptr will automatically delete the Customer
        return true;
    }
    return false;
}

// Displays all customers and their associated accounts
void BankAccountContainer::displayAllCustomers() const
{
    for (const auto& customer : customers)
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
        [](const std::unique_ptr<Customer>& a, const std::unique_ptr<Customer>& b) {
            return a->getLastName() < b->getLastName();
        });
}

// Generates the next unique account number
int BankAccountContainer::getNextAccountNumber()
{
    return accountNumberGenerator++;
}

// Saves all customers and their associated accounts to a binary file
void BankAccountContainer::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for writing: " << filename << std::endl;
        return;
    }

    // Write number of customers first
    size_t numCustomers = customers.size();
    file.write(reinterpret_cast<const char*>(&numCustomers), sizeof(numCustomers));

    // Write each customer
    for (const auto& customer : customers) {
        // Write customer ID
        std::string id = customer->getId();
        size_t idLength = id.length();
        file.write(reinterpret_cast<const char*>(&idLength), sizeof(idLength));
        file.write(id.c_str(), idLength);

        // Write first name
        std::string firstName = customer->getFirstName();
        size_t firstNameLength = firstName.length();
        file.write(reinterpret_cast<const char*>(&firstNameLength), sizeof(firstNameLength));
        file.write(firstName.c_str(), firstNameLength);

        // Write last name
        std::string lastName = customer->getLastName();
        size_t lastNameLength = lastName.length();
        file.write(reinterpret_cast<const char*>(&lastNameLength), sizeof(lastNameLength));
        file.write(lastName.c_str(), lastNameLength);
    }

    // Write number of accounts
    size_t numAccounts = accounts.size();
    file.write(reinterpret_cast<const char*>(&numAccounts), sizeof(numAccounts));

    // Write each account
    for (const auto& account : accounts) {
        // Write account type
        std::string type = account->getAccountType();
        size_t typeLength = type.length();
        file.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
        file.write(type.c_str(), typeLength);

        // Write account number
        int accountNum = account->getAccountNumber();
        file.write(reinterpret_cast<const char*>(&accountNum), sizeof(accountNum));

        // Write balance
        double balance = account->getBalance();
        file.write(reinterpret_cast<const char*>(&balance), sizeof(balance));

        // Write customer ID
        std::string customerId = account->getAccountHolder();  // This should be the customer ID instead
        size_t customerIdLength = customerId.length();
        file.write(reinterpret_cast<const char*>(&customerIdLength), sizeof(customerIdLength));
        file.write(customerId.c_str(), customerIdLength);
    }

    file.close();
    std::cout << "Data saved successfully to " << filename << std::endl;
}

//loads all customers and their associated accounts from a binary file
void BankAccountContainer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for reading: " << filename << std::endl;
        return;
    }

    // Clear existing data
    accounts.clear();
    customers.clear();

    try {
        // Read number of customers first (so we can associate accounts with customers)
        size_t numCustomers;
        file.read(reinterpret_cast<char*>(&numCustomers), sizeof(numCustomers));

        // Read each customer
        for (size_t i = 0; i < numCustomers; ++i) {
            // Read customer ID
            size_t idLength;
            file.read(reinterpret_cast<char*>(&idLength), sizeof(idLength));
            std::string id(idLength, '\0');
            file.read(&id[0], idLength);

            // Read first name
            size_t firstNameLength;
            file.read(reinterpret_cast<char*>(&firstNameLength), sizeof(firstNameLength));
            std::string firstName(firstNameLength, '\0');
            file.read(&firstName[0], firstNameLength);

            // Read last name
            size_t lastNameLength;
            file.read(reinterpret_cast<char*>(&lastNameLength), sizeof(lastNameLength));
            std::string lastName(lastNameLength, '\0');
            file.read(&lastName[0], lastNameLength);

            auto customer = std::make_unique<Customer>(firstName, lastName);
            customers.push_back(std::move(customer));
        }

        // Read number of accounts
        size_t numAccounts;
        file.read(reinterpret_cast<char*>(&numAccounts), sizeof(numAccounts));

        // Read each account
        for (size_t i = 0; i < numAccounts; ++i) {
            // Read account type
            size_t typeLength;
            file.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
            std::string type(typeLength, '\0');
            file.read(&type[0], typeLength);

            // Read account number
            int accountNum;
            file.read(reinterpret_cast<char*>(&accountNum), sizeof(accountNum));

            // Read balance
            double balance;
            file.read(reinterpret_cast<char*>(&balance), sizeof(balance));

            // Read customer ID for this account
            size_t customerIdLength;
            file.read(reinterpret_cast<char*>(&customerIdLength), sizeof(customerIdLength));
            std::string customerId(customerIdLength, '\0');
            file.read(&customerId[0], customerIdLength);

            // Create appropriate account type
            std::unique_ptr<BankAccount> newAccount;
            if (type == "Checking") {
                newAccount = std::make_unique<CheckingAccount>(balance);
            } else if (type == "Savings") {
                newAccount = std::make_unique<SavingsAccount>(balance);
            } else if (type == "MMDA") {
                newAccount = std::make_unique<MMDA>(balance);
            } else if (type == "Credit") {
                newAccount = std::make_unique<CreditAccount>(balance);
            } else if (type == "One Year CD") {
                newAccount = std::make_unique<OneYearCD>(balance);
            } else if (type == "Three Month CD") {
                newAccount = std::make_unique<ThreeMonthCD>(balance);
            } else if (type == "Six Month CD") {
                newAccount = std::make_unique<SixMonthCD>(balance);
            }

            if (newAccount) {
                newAccount->setAccountNumber(accountNum);
                // Find and set the customer
                Customer* customer = findCustomerById(customerId);
                if (customer) {
                    newAccount->setCustomer(customer);
                }
                accounts.push_back(std::move(newAccount));
            }
        }

        file.close();
        std::cout << "Data loaded successfully from " << filename << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error loading data: " << e.what() << std::endl;
        file.close();
    }
}

//adds a new bank account
void BankAccountContainer::addAccount(BankAccount* account) {
    if (account) {  // Add null check
        accounts.push_back(std::unique_ptr<BankAccount>(account));
    }
}

//Destructor to clean up dynamically allocated memory
BankAccountContainer::~BankAccountContainer() = default;

BankAccount* BankAccountContainer::findAccountByNumber(int accountNumber) {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account.get();
        }
    }
    return nullptr;
}

bool BankAccountContainer::deleteAccount(int accountNumber) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](const std::unique_ptr<BankAccount>& account) {
            return account->getAccountNumber() == accountNumber;
        });
    
    if (it != accounts.end()) {
        accounts.erase(it);  // unique_ptr will handle deletion
        return true;
    }
    return false;
}

void BankAccountContainer::displayAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "No accounts found." << std::endl;
        return;
    }

    std::cout << "\n===== Account Listing =====" << std::endl;
    std::cout << std::fixed << std::setprecision(2);  // Format currency output
    for (const auto& account : accounts) {
        std::cout << "Account Number: " << account->getAccountNumber() << std::endl;
        std::cout << "Account Type: " << account->getAccountType() << std::endl;
        std::cout << "Account Holder: " << account->getAccountHolder() << std::endl;
        std::cout << "Balance: $" << account->getBalance() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

void BankAccountContainer::displayAccountsSortedByBalance() const {
    if (accounts.empty()) {
        std::cout << "No accounts found." << std::endl;
        return;
    }

    // Create a vector of raw pointers for sorting
    std::vector<BankAccount*> sortedAccounts;
    sortedAccounts.reserve(accounts.size());  // Preallocate space

    // Get raw pointers from unique_ptrs
    for (const auto& account : accounts) {
        if (account) {  // Check if unique_ptr holds a valid pointer
            sortedAccounts.push_back(account.get());
        }
    }

    if (sortedAccounts.empty()) {
        std::cout << "No valid accounts to display." << std::endl;
        return;
    }

    // Sort by balance
    std::sort(sortedAccounts.begin(), sortedAccounts.end(),
        [](const BankAccount* a, const BankAccount* b) {
            if (a && b) {  // Ensure both pointers are valid
                return a->getBalance() > b->getBalance();
            }
            return false;
        });

    // Display sorted accounts
    std::cout << "\n===== Accounts Sorted by Balance (Highest to Lowest) =====" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    
    for (const BankAccount* account : sortedAccounts) {
        if (account) {  // One final check before using the pointer
            std::cout << "Account Number: " << account->getAccountNumber() << std::endl;
            std::cout << "Account Type: " << account->getAccountType() << std::endl;
            std::cout << "Account Holder: " << account->getAccountHolder() << std::endl;
            std::cout << "Balance: $" << account->getBalance() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

void BankAccountContainer::displayAccountsSortedByLastName() const {
    if (accounts.empty()) {
        std::cout << "No accounts found." << std::endl;
        return;
    }

    // Create a vector of pointers to sort
    std::vector<const BankAccount*> sortedAccounts;
    for (const auto& account : accounts) {
        sortedAccounts.push_back(account.get());
    }

    // Sort by account holder's last name
    std::sort(sortedAccounts.begin(), sortedAccounts.end(),
        [](const BankAccount* a, const BankAccount* b) {
            std::string aHolder = a->getAccountHolder();
            std::string bHolder = b->getAccountHolder();
            // Extract last name (assuming format is "First Last")
            size_t aSpace = aHolder.find_last_of(' ');
            size_t bSpace = bHolder.find_last_of(' ');
            std::string aLast = (aSpace != std::string::npos) ? aHolder.substr(aSpace + 1) : aHolder;
            std::string bLast = (bSpace != std::string::npos) ? bHolder.substr(bSpace + 1) : bHolder;
            return aLast < bLast;
        });

    std::cout << "\n===== Accounts Sorted by Customer Last Name =====" << std::endl;
    std::cout << std::fixed << std::setprecision(2);  // Format currency output
    for (const auto* account : sortedAccounts) {
        std::cout << "Account Holder: " << account->getAccountHolder() << std::endl;
        std::cout << "Account Number: " << account->getAccountNumber() << std::endl;
        std::cout << "Account Type: " << account->getAccountType() << std::endl;
        std::cout << "Balance: $" << account->getBalance() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
