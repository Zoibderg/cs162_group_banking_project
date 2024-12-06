#pragma once

#include "BankAccount.h"

/**
 * SixMonthCD class represents a six-month certificate of deposit account.
 */
class SixMonthCD : public BankAccount
{
public:
    /**
     * Constructor for SixMonthCD.
     * @param initialBalance The starting balance of the CD account.
     */
    SixMonthCD(double initialBalance);
};
