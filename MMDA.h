#ifndef MMDA_H
#define MMDA_H

#include "MoneyMarketBase.h"
#include "BalanceHandler.h"

/**
 * Money Market Deposit Account class
 */
class MMDA : public MoneyMarketBase {
private:
    double balance;
    BalanceHandler* handler;

public:
    /**
     * Default constructor
     */
    MMDA();

    /**
     * Constructor with initial balance
     * @param initialBalance Initial account balance
     */
    explicit MMDA(double initialBalance);

    /**
     * Destructor
     */
    ~MMDA() override;

    /**
     * Gets the current balance
     * @return Current account balance
     */
    double getBalance() const;

    /**
     * Sets the account balance
     * @param amount New balance amount
     */
    void setBalance(double amount);

    /**
     * Withdraws money from the account
     * @param amount Amount to withdraw
     */
    void withdraw(double amount);

    /**
     * Applies penalty to the account
     */
    void applyPenalty();
};

#endif 