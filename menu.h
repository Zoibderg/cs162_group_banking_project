#pragma once

#include "BankAccountContainer.h"

/**
 * @class Menu
 * @brief Handles all user interface and menu operations
 * 
 * This class manages the banking system's user interface, providing menus
 * for account management, transactions, and CD operations.
 */
class Menu {
private:
    BankAccountContainer& container; ///< Reference to the main account container

    /**
     * @brief Handles the creation of new accounts
     */
    void addAccount();

    /**
     * @brief Displays details for a specific account
     */
    void viewAccountDetails();

    /**
     * @brief Handles account information updates
     */
    void updateAccountInformation();

    /**
     * @brief Handles account deletion
     */
    void deleteAccount();

    /**
     * @brief Helper function to select existing or create new customer
     * @return Pointer to selected/created customer, nullptr if operation fails
     */
    Customer* selectOrCreateCustomer();

    /**
     * @brief Displays accounts sorted by balance
     */
    void displayAccountsSortedByBalance();

    /**
     * @brief Displays accounts sorted by customer last name
     */
    void displayAccountsSortedByLastName();

public:
    /**
     * @brief Constructor
     * @param cont Reference to the BankAccountContainer
     */
    explicit Menu(BankAccountContainer& cont) : container(cont) {}
    
    /**
     * @brief Displays the main menu options
     */
    void displayMainMenu();

    /**
     * @brief Displays the account management menu
     */
    void displayAccountMenu();

    /**
     * @brief Displays the transaction management menu
     */
    void displayTransactionMenu();

    /**
     * @brief Displays the CD management menu
     */
    void displayCDMenu();

    /**
     * @brief Entry point for the menu system
     */
    void start();
};
