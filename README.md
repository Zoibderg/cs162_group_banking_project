# Bank Account Management System

![C++](https://img.shields.io/badge/C%2B%2B-11-blue.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![Status](https://img.shields.io/badge/status-completed-success.svg)

#### Team Members

* Jordan Bassett
* Tayler Caufield
* Austin Tesch

#### Course: CS162 | Instructor: Steve Smiley

## Overview

This project implements a comprehensive bank account management system that effectively manages multiple bank account types including checking accounts, certificates of deposit (CDs), and money market accounts. The system utilizes object-oriented design principles and robust data structures to handle account operations and customer management.

## Implemented Features

### Account Types
- Basic Bank Account (Base functionality)
- Checking Account
- Money Market Deposit Account (MMDA)
- Certificates of Deposit (CDs):
  - Three Month CD
  - Six Month CD
  - One Year CD

### Core Functionality
- Account Management:
  - Create and manage multiple account types
  - Track account status and balances
  - Generate account statements
  - Process deposits and withdrawals
  - Maintain transaction history

- Customer Management:
  - Customer profile creation
  - Multiple accounts per customer
  - Account holder information tracking

### Implemented Class Structure
- Base Classes:
  - `BankAccount`: Foundation for all account types
  - `CertificateOfDepositBase`: Base for CD accounts
  - `MoneyMarketBase`: Base for money market accounts

- Account Types:
  - `CheckingAccount`
  - `MMDA` (Money Market Deposit Account)
  - `ThreeMonthCD`
  - `SixMonthCD`
  - `OneYearCD`

- Supporting Classes:
  - `Customer`: Manages customer information
  - `Menu`: Handles user interface operations

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

### Phase 3

#### Polymorphic Functions and Dynamic Binding

* **withdraw()**: Some account types handle penalties differently. For instance, `SavingsAccount` applies penalties for low balances, and `CDAccount` applies maturity penalties. These penalties need to be specific to the account type, so this function should be polymorphic.
* **deposit()**: For most accounts, the deposit logic might be the same. However, `CreditAccount` might have special rules (e.g., paying off credit or applying a minimum payment). Making this function virtual allows for these customizations.
* **applyMonthlyInterest()**: Accounts like `SavingsAccount` and `MoneyMarketAccount` earn monthly interest. Since the interest rate and calculations are specific to each type of account, this function should be polymorphic.
* **generateStatement()**: For reporting different account details (including penalties, interest, or overdraft limits), this function can also be virtual to handle specific account requirements.

#### Tracking Multiple Accounts for a Single Customer

One way to store multiple accounts for a customer could be to allocate individual arrays for each customer so that you can either pull up the whole array and all the accounts or use a pointer to pick a single account from the list. Another approach could be to write into a file for each customer and label them by customer name to easily access throughout the program.

## UML Diagram

<figure><img src=".gitbook/assets/Untitled Diagram-5.png" alt=""><figcaption></figcaption></figure>
