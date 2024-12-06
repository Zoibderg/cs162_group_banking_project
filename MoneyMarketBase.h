#ifndef MONEY_MARKET_BASE_H
#define MONEY_MARKET_BASE_H

/**
 * @class MoneyMarketBase
 * @brief Base class for Money Market accounts
 * 
 * Provides core functionality for money market accounts including
 * interest rates and penalty calculations.
 */
class MoneyMarketBase {
protected:
    const double monthlyInterest = 1.25;   ///< Monthly interest rate (1.25%)
    const double maturityPenalty = 0.0;    ///< Penalty rate for early withdrawal

public:
    virtual ~MoneyMarketBase() = default;

    /**
     * @brief Default constructor
     */
    MoneyMarketBase();

    /**
     * @brief Calculates penalty for early withdrawal
     * @param amount Withdrawal amount
     * @return Calculated penalty amount
     */
    virtual double withdrawalPenalty(double amount) const;

    /**
     * @brief Gets the current monthly interest rate
     * @return Monthly interest rate as a percentage
     */
    virtual double getMonthlyInterest() const;

    /**
     * @brief Gets the current maturity penalty rate
     * @return Maturity penalty rate as a percentage
     */
    virtual double getMaturityPenalty() const;
};

#endif 