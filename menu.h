#pragma once

#include "BankAccountContainer.h"

class Menu
{
private:
    BankAccountContainer container; // Manages all accounts and customers

    void displayMainMenu();
    void displayAccountMenu();
    void displayTransactionMenu();
    void displayCDMenu();

    void addAccount();
    void viewAccountDetails(); // Declaration for viewing account details
    void updateAccountInformation(); // Declaration for updating account information
    void deleteAccount(); // Declaration for deleting accounts

    Customer* selectOrCreateCustomer();

public:
    void start(); // Entry point to start the menu system
};
