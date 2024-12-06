#ifndef MMDA_H
#define MMDA_H

#include "MoneyMarketBase.h"
#include "BalanceHandler.h"
#include "BankAccount.h"

/**
 * Money Market Deposit Account class
 */
class MMDA : public BankAccount, public MoneyMarketBase {
private:
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
     * Withdraws money from the account
     * @param amount Amount to withdraw
     */
    void withdraw(double amount);

    /**
     * Applies penalty to the account
     */
    void applyPenalty();

    /**
     * Sets the balance of the account
     * @param newBalance New account balance
     */
    void setBalance(double newBalance);

    /**
     * Gets the balance of the account
     * @return Account balance
     */
    double getBalance() const;
};

#endif 