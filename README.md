---
icon: building-columns
---

# Banking Project Overview

## Phase 1

### **Appropriate primitive data types needed for a bank account system**

**a.     Account Holder Name: string.**&#x20;

Probably two using two string variables for first\_name and last\_name to keep names structured.

**b.     Account Balance: double**

Provides the necessary precision to handle financial data accurately.

**c.     Account Type: string**

Allows flexibility to store different account types as text (e.g., "Checking", "Savings", “Credit”).

**d.     Interest Rate: double**

Precision is important for interest rate calculations, especially when compounding.

**e.     Transaction Amount: double**

Precision is needed for accurate transaction handling.

**f.      Transaction Date: time\_t**

Typically, a time\_t, often represented as a long int.

**g.     Customer ID: int**

A unique integer identifier for each customer.

**h.    PIN/Password: string**

Although stored as a string, this value should be hashed or encrypted for security.



### **Static member variables**

**1.     The bank name:** Since all accounts belong to the same bank, the bank name can be defined as a static member variable. This allows all instances of the class to share the same bank name without duplicating data in each account object. Additionally, if the bank name ever needs to be updated, it can be changed in one place for all accounts.

**2.     Interest Rate for Savings Accounts:** All savings accounts share the same interest rate. This makes it easy to update the rate across all accounts if needed.

**3.     Transaction Fee:** a static member could store this value to apply consistently across accounts.

**4.     Total Number of Accounts:** Useful for generating unique account numbers or for tracking growth.



### **Constructors needed**

**a.     Default constructor**

A default constructor is useful for creating an empty account with default values. This could be helpful when initializing an account object before setting its specific details.

**b.    Overloaded Constructor**

An overloaded constructor would allow the creation of an account with specific details provided at the time of creation. This constructor could take parameters like the account number, initial balance, account type, and customer ID to fully initialize an account when it is created.



**Seven Classes to be designed:** BankAccount, SavingsAccount, CheckingAccount. CreditAccount, Transaction, Customer, BankAccountContainer

## Purpose of each class:

**a.      BankAccount (Base Class)**

Base class for different account types, including attributes and methods common to all accounts, like account\_number, balance, and basic deposit/withdraw methods.

**b.    SavingsAccount (Derived from BankAccount)**

Adds features specific to savings accounts, such as an interest\_rate attribute and methods for interest calculation. Inherits core functionality from BankAccount.

**c.     CheckingAccount (Derived from BankAccount)**

Adds checking-specific attributes and methods, such as an overdraft\_limit and potentially check-writing functions. Also inherits common functionality from BankAccount.

**d.    CreditAccount (Derived from BankAccount)**

Represents credit card accounts with features such as a credit\_limit, APR (annual percentage rate), and possibly reward points. This class can handle credit-specific methods, such as calculating monthly payments or interest on outstanding balances.

**e.     Transaction**

Manages the processing of various transaction types—deposits, withdrawals, and transfers. It could also store transaction-specific details, like transaction\_id, transaction\_date, transaction\_amount, and transaction\_type. As well as having methods to reverse or cancel any transactions.

**f.      Customer**

Stores customer details, such as name, address, contact\_info, and a list of associated BankAccount objects. This class could also include methods for managing and accessing the customer’s accounts as well as updating contact info.

**g.     BankAccount Container**

Acts as a manager for all BankAccount objects within the system. This container would oversee the creation, storage, and retrieval of accounts, allowing the system to efficiently manage multiple accounts across multiple customers. It could include methods to find accounts by account\_number or customer\_id and to handle bulk transactions if needed.



## Class relationships

**a.     “Is-a” Relationship (Inheritance)**

BankAccount serves as the base class, and specific account types inherit from it. This defines an “is-a” relationship because SavingsAccount, CheckingAccount, and CreditAccount are all a BankAccount.

**b.     “Has-a” Relationship (Composition)**

Customer has a “has-a” relationship with BankAccount because each Customer can hold one or more BankAccount objects. This is composition because a Customer “has-a” BankAccount. A Transaction “has-a” date, amount, and is associated with one or more BankAccount objects (the accounts involved in the transaction).

The BankAccount Container also has a composition relationship with BankAccount objects, as it manages a collection of accounts within the system.



## UML:

<figure><img src=".gitbook/assets/cs162_group_project_uml.png" alt=""><figcaption></figcaption></figure>
