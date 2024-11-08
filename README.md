# Bank Account Management System

#### Team Members

* Jordan Bassett
* Tayler Caufield
* Austin Tesch

#### Course: CS162 | Instructor: Steve Smiley

## Overview

This project aims to develop a bank account management system that can effectively manage multiple bank accounts with various features, such as savings, checking, and credit accounts. It utilizes a series of data structures to create, save, and load account information in different formats. The project is divided into phases, with the current status covering Phases 1 and 2.

## Features to be Implemented

### Account Attributes (Phase 1)

* **Account Holder Name**: Managed using `string` variables for both first and last names to maintain structure.
* **Account Balance**: Stored as `double` for precise financial calculations.
* **Account Type**: Stores different types of accounts (e.g., "Checking", "Savings", "Credit") as text.
* **Interest Rate**: `double` type to handle precision in compounding calculations.
* **Transaction Amount**: `double` type to ensure accuracy.
* **Transaction Date**: Uses `time_t` to record the exact date of transactions.
* **Customer ID**: A unique `int` identifier for each customer.
* **PIN/Password**: Stored as a `string` and should be hashed or encrypted for security purposes.

#### Account Relationships and Class Hierarchy

The system employs object-oriented design, emphasizing both **inheritance** and **composition**:

* **Inheritance**: `BankAccount` is the base class for other account types such as `SavingsAccount`, `CheckingAccount`, and `CreditAccount`.
* **Composition**: The `Customer` class maintains a "has-a" relationship with `BankAccount` objects, indicating that customers can hold multiple accounts.
* **Classes Designed**:
  * `BankAccount` (Base Class)
  * `SavingsAccount`, `CheckingAccount`, `CreditAccount` (Derived from `BankAccount`)
  * `Transaction` (Handles transactions such as deposits, withdrawals, and transfers)
  * `Customer` (Stores customer information)
  * `BankAccountContainer` (Manages all `BankAccount` objects within the system)

#### Constructors

* **Default Constructor**: Initializes empty accounts with default values.
* **Overloaded Constructor**: Creates accounts with specific details at the time of initialization, allowing greater control over data.

#### Static Member Variables

* **Bank Name**: Shared across all accounts to avoid redundancy.
* **Interest Rate for Savings Accounts**: Static value to be easily updated.
* **Transaction Fee**: Consistent across all accounts.
* **Total Number of Accounts**: Useful for tracking and generating unique identifiers.

#### UML Diagram

<figure><img src=".gitbook/assets/cs162_group_project_uml.png" alt=""><figcaption></figcaption></figure>

### Saving and Loading Account Data (Phase 2)

This phase focuses on implementing file handling mechanisms and defining data structures to enhance the functionality and robustness of the banking system.

### File Handling

**Binary vs. Text Files:**&#x20;

* **Binary Files:** Ideal for large datasets due to compact storage and faster read/write speeds. They also provide a level of security as the data is stored in a raw format, making it harder to read without specific software.&#x20;
* **Text Files:** Offer advantages in terms of readability and portability across different systems. They are easier to debug and modify due to their human-readable format.

**Data Type Considerations:**

Customer names will be stored using the `std::string` data type.

**Writing Multiple Objects to File:**

File streams enable writing multiple objects to a file. This will be utilized to store customer and account data. Data Structures

**Checking Account Structure:**

A `CheckingAccount` structure is defined to organize variables related to a checking account: Input Validation

```
struct CheckingAccount {
    int accountNumber;          // Account number of the checking account
    std::string accountHolder;  // Name of the account holder
    double balance;             // Current balance of the account
    std::string accountType;    // Type of the account (e.g., "Checking")
    std::string dateOpened;     // Date when the account was opened
};
```

**File Handling:**

* Check if the file exists and can be accessed.
* Validate that the file's content adheres to the expected format.
* Ensure the data types within the file match the program's requirements.

```
// Check if the file opened successfully
if (!inputFile.is_open()) {
  std::cerr << "Error: Could not open the file." << std::endl;
  return 1;
}

// Validate data format (example)
if (!(lineStream >> value)) {
  std::cerr << "Error: Invalid data format on line " << lineNumber 
            << ". Expected an integer." << std::endl;
  continue; 
}

// Validate value is non-negative (example)
if (value < 0) {
  std::cerr << "Error: Value on line " << lineNumber 
            << " should not be negative." << std::endl;
  continue;
}
```

