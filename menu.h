//
// Created by Austin Tesch on 12/2/24.
//
#ifndef MENU_H
#define MENU_H
#include "Customer.h"
#include "BankAccountContainer.h"

class Menu {
private:
    BankAccountContainer& container;  // Reference to the container

public:
    /**
     * Constructor that takes a reference to BankAccountContainer
     * @param cont Reference to the BankAccountContainer
     */
    explicit Menu(BankAccountContainer& cont) : container(cont) {}

    /**
     * Displays the main menu
     */
    void displayMainMenu();

    /**
     * Displays the account management menu
     */
    void displayAccountMenu();

    /**
     * Displays the transaction menu
     */
    void displayTransactionMenu();

    /**
     * Displays the CD menu
     */
    void displayCDMenu();

private:
    /**
     * Handles adding a new account
     */
    void addAccount();

    /**
     * Helper function to select or create a customer
     * @return Pointer to selected or created customer, nullptr if operation fails
     */
    Customer* selectOrCreateCustomer();

    // Displays the details of a specific account by its account number
    void viewAccountDetails();

     //Updates the info of an account such as balance, status, holder.
     void updateAccountInformation();

    //Deletes an account by its account number
    void deleteAccount();

    //Processes a new transaction (Deposit or Withdrawal)
    void processTransaction();

    //Cancels an existing transaction by its transaction ID
    void cancelTransaction();

};

#endif
