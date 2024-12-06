#ifndef MMDA_H
#define MMDA_H

#include "MoneyMarketBase.h"
#include "BalanceHandler.h"
#include "BankAccount.h"

/**
 * @class MMDA
 * @brief Money Market Deposit Account implementation
 * 
 * This class represents a Money Market Deposit Account which combines features
 * of both checking and savings accounts with higher interest rates and
 * minimum balance requirements.
 */
class MMDA : public BankAccount, public MoneyMarketBase {
private:
    BalanceHandler* handler;  ///< Handler for balance-related operations

public:
    /**
     * @brief Default constructor
     */
    MMDA();

    /**
     * @brief Constructor with initial balance
     * @param initialBalance Initial deposit amount
     */
    explicit MMDA(double initialBalance);

    /**
     * @brief Destructor to clean up handler
     */
    ~MMDA() override;

    /**
     * @brief Withdraws money from the account
     * @param amount Amount to withdraw
     */
    void withdraw(double amount) override;

    /**
     * @brief Applies early withdrawal or other penalties
     */
    void applyPenalty();

    /**
     * @brief Sets the account balance
     * @param newBalance New balance amount
     */
    void setBalance(double newBalance);

    /**
     * @brief Gets the current balance
     * @return Current account balance
     */
    double getBalance() const override;
};

#endif 