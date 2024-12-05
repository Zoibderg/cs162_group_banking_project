#ifndef BALANCE_HANDLER_H
#define BALANCE_HANDLER_H

/**
 * Class for handling balance operations
 */
class BalanceHandler {
public:
    /**
     * Default constructor
     */
    BalanceHandler() = default;

    /**
     * Virtual destructor
     */
    virtual ~BalanceHandler() = default;

    /**
     * Handles balance operations
     * @param balance The balance to handle
     */
    virtual void handleBalance(double balance);
};

#endif 