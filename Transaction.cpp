#include "Transaction.h"

/**
 * Constructor to initialize the transaction details.
 * @param id The unique identifier for the transaction.
 * @param type The type of the transaction (e.g., "Deposit", "Withdrawal").
 * @param amt The amount involved in the transaction.
 * @param transaction_date The date of the transaction (in "YYYY-MM-DD" format).
 * @param acct_num The account number associated with this transaction.
 */
Transaction::Transaction(int id, const std::string& type, double amt, const std::string& transaction_date, int acct_num)
    : transaction_id(id), transaction_type(type), amount(amt), date(transaction_date), account_number(acct_num) {}

/**
 * Getter for Transaction ID.
 */
int Transaction::getTransactionId() const {
    return transaction_id;
}

/**
 * Getter for Transaction Type.
 */
std::string Transaction::getTransactionType() const {
    return transaction_type;
}

/**
 * Getter for Amount.
 */
double Transaction::getAmount() const {
    return amount;
}

/**
 * Getter for Date.
 */
std::string Transaction::getDate() const {
    return date;
}

/**
 * Getter for Account Number.
 */
int Transaction::getAccountNumber() const {
    return account_number;
}

/**
 * Displays transaction details.
 * Outputs the transaction information, including transaction ID, type, amount, date, and account number.
 */
void Transaction::displayTransaction() const {
    std::cout << "Transaction ID: " << transaction_id << "\n"
              << "Type: " << transaction_type << "\n"
              << "Amount: $" << amount << "\n"
              << "Date: " << date << "\n"
              << "Account Number: " << account_number << "\n";
}
