#ifndef MONEY_MARKET_BASE_H
#define MONEY_MARKET_BASE_H

/**
 * Base class for Money Market accounts with defined interest rates and penalties
 */
class MoneyMarketBase {
protected:
    const double monthlyInterest = 1.25;
    const double maturityPenalty = 0.0;

public:
    virtual ~MoneyMarketBase() = default;

    /**
     * Default constructor
     */
    MoneyMarketBase();

    /**
     * Calculates withdrawal penalty based on amount
     * @param amount The withdrawal amount
     * @return The calculated penalty
     */
    virtual double withdrawalPenalty(double amount) const;

    /**
     * Gets the monthly interest rate
     * @return Monthly interest rate
     */
    virtual double getMonthlyInterest() const;

    /**
     * Gets the maturity penalty rate
     * @return Maturity penalty rate
     */
    virtual double getMaturityPenalty() const;
};

#endif 