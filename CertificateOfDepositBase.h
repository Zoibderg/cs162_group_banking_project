#ifndef CERTIFICATE_OF_DEPOSIT_BASE_H
#define CERTIFICATE_OF_DEPOSIT_BASE_H

/**
 * Base class for Certificate of Deposit accounts
 */
class CertificateOfDepositBase {
protected:
    double balance;

public:
    /**
     * Default constructor
     */
    CertificateOfDepositBase();

    /**
     * Constructor with initial balance
     * @param balance Initial balance for the CD
     */
    explicit CertificateOfDepositBase(double balance);

    /**
     * Gets the current balance
     * @return Current balance
     */
    virtual double getBalance() const;

    /**
     * Sets the balance to a new value
     * @param balance New balance value
     */
    virtual void setBalance(double balance);

    /**
     * Calculates interest for the CD
     * @return Calculated interest amount
     */
    virtual double calculateInterest() const = 0;
};

#endif 