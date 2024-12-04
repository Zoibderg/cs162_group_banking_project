#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
private:
    int transaction_id;               // Unique identifier for the transaction
    std::string transaction_type;     // Type of transaction (e.g., "Deposit", "Withdrawal")
    double amount;                    // Amount involved in the transaction
    std::string date;                 // Date of the transaction in string format (e.g., "YYYY-MM-DD")
    int account_number;               // Account number associated with this transaction

public:
    // Constructor to initialize the transaction details
    Transaction(int id, const std::string& type, double amt, const std::string& transaction_date, int acct_num);

    // Getters for each attribute
    [[nodiscard]] int getTransactionId() const;
    [[nodiscard]] std::string getTransactionType() const;
    [[nodiscard]] double getAmount() const;
    [[nodiscard]] std::string getDate() const;
    [[nodiscard]] int getAccountNumber() const;

    // Displays transaction details
    void displayTransaction() const;
};

#endif // TRANSACTION_H