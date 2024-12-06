#pragma once

#include "BankAccountContainer.h"

class Menu
{
private:
    BankAccountContainer& container; // Reference to container

    void addAccount();
    void viewAccountDetails();
    void updateAccountInformation();
    void deleteAccount();
    Customer* selectOrCreateCustomer();
    void displayAccountsSortedByBalance();
    void displayAccountsSortedByLastName();

public:
    explicit Menu(BankAccountContainer& cont) : container(cont) {}
    
    void displayMainMenu();
    void displayAccountMenu();
    void displayTransactionMenu();
    void displayCDMenu();
    void start(); // Entry point to start the menu system
};
