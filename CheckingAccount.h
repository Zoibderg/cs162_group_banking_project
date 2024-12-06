#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "BankAccount.h"

/**
 * @class CheckingAccount
 * @brief Represents a checking account with overdraft protection
 * 
 * This class extends the base BankAccount class to provide checking account
 * specific features like overdraft protection and associated fees.
 */
class CheckingAccount : public BankAccount {
private:
    double overdraft_limit;  ///< Maximum allowed overdraft amount

public:
    /**
     * @brief Default constructor
     */
    CheckingAccount();

    /**
     * @brief Constructor with initial balance
     * @param initialBalance Initial deposit amount
     */
    explicit CheckingAccount(double initialBalance);

    /**
     * @brief Checks if account has exceeded overdraft limit
     */
    void check_overdraft();

    /**
     * @brief Applies standard overdraft fee to the account
     */
    void apply_overdraft_fee();
};

#endif
