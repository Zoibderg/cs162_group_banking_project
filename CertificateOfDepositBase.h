#ifndef CERTIFICATE_OF_DEPOSIT_BASE_H
#define CERTIFICATE_OF_DEPOSIT_BASE_H

/**
 * @class CertificateOfDepositBase
 * @brief Base class for all Certificate of Deposit accounts
 * 
 * Provides common functionality for CD accounts including
 * balance management and interest calculations.
 */
class CertificateOfDepositBase {
protected:
    double cdBalance;  ///< Current balance of the CD

public:
    /**
     * @brief Default constructor
     */
    CertificateOfDepositBase() : cdBalance(0.0) {}

    /**
     * @brief Constructor with initial balance
     * @param balance Initial deposit amount
     */
    explicit CertificateOfDepositBase(double balance) : cdBalance(balance) {}

    /**
     * @brief Gets the current CD balance
     * @return Current balance
     */
    virtual double getBalance() const { return cdBalance; }

    /**
     * @brief Updates the CD balance
     * @param balance New balance amount
     */
    virtual void setBalance(double balance) { cdBalance = balance; }

    /**
     * @brief Pure virtual function for interest calculation
     * @return Calculated interest amount
     */
    virtual double calculateInterest() const = 0;
};

#endif 