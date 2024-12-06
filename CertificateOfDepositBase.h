#ifndef CERTIFICATE_OF_DEPOSIT_BASE_H
#define CERTIFICATE_OF_DEPOSIT_BASE_H

/**
 * Base class for Certificate of Deposit accounts
 */
class CertificateOfDepositBase {
protected:
    double cdBalance;

public:
    /**
     * Default constructor
     */
    CertificateOfDepositBase() : cdBalance(0.0) {}

    /**
     * Constructor with initial balance
     * @param balance Initial balance for the CD
     */
    explicit CertificateOfDepositBase(double balance) : cdBalance(balance) {}

    /**
     * Gets the current balance
     * @return Current balance
     */
    virtual double getBalance() const { return cdBalance; }

    /**
     * Sets the balance to a new value
     * @param balance New balance value
     */
    virtual void setBalance(double balance) { cdBalance = balance; }

    /**
     * Calculates interest for the CD
     * @return Calculated interest amount
     */
    virtual double calculateInterest() const = 0;
};

#endif 