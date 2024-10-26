# Banking Project Overview

## Phase 1

### Scenario:

Samediff Bank has a 25-year-old banking account system. It was created using procedural programming. Samediff Bank needs to improve the security and maintainability of the system using an object-oriented programming (OOP) approach. Their bank manager has decided to hire you to develop, implement, and test a new OOP application using efficient data structures and programming techniques.

**Phase 1 Requirements: Answers to the discussion questions, using Phase 1 Grading Rubric to optimize your grade.**

**Use the following questions to help guide your team to accomplish tasks required in Phase 1:**

**(4 points possible) What are appropriate primitive data types needed for a bank account system? List them.**

+ Account Holder Name: string, Maybe one for first name and one for last name

+ Account Balance: double (Most precise)

+ Account Type: string (Checking, savings, etc)

+ Interest Rate: double

+ Transaction Amount: double

+ Transaction Date: time_t stuff. Think it comes out to a long int

+ Customer ID: int

+ PIN/Password: string (scrambled/hashed)

**(2 points possible) When using a class for the scenario provided, will there be any static member variables? If yes, explain reasons to support your idea.**

+ bank name: to avoid storing it repeatedly in each account object
+ interest rates: to keep it consistent for all savings, credit, etc. accounts
+ transaction fees?
+ minimum balance requirements

**(2 points possible) What kind of constructors would you need? List them.**

+ A default constructor for creating an empty account. 
+ An overloaded constructor for setting account details like account number, balance, and type at creation.
+ According to an account system, customers can have more than one type of an account.

**(4 points possible) How many classes should you design?**

+ SavingsAccount, CheckingAccount, Credit Account?
+ Maybe a BankAccount container to hold the above
+ Transaction: Handles deposits, withdrawals, transfers.
+ Customer? For address and other info

**(4 points possible ) Write the purpose of each class.**

+ BankAccount: base class for the different types of bank accounts, like SavingsAccount and CheckingAccount. It would hold common attributes and methods like account number, balance, and deposit/withdrawal functionality.
+ SavingsAccount: would inherit from BankAccount and have additional attributes and methods specific to savings accounts, like interest rate calculation.
+ CheckingAccount: CheckingAccount would also inherit from BankAccount and handle checking account-specific features, like overdraft limits or check writing.
+ CreditAccount: represent credit card accounts and manage features like credit limit, APR, and reward points?
+ Transaction: processing different types of transactions, such as deposits, withdrawals, and transfers, for all account types.
+ Customer: store customer information, such as name, address, contact details, and a list of BankAccounts associated with the customer.
+ BankAccount Container: to hold and manage all the bank accounts within the system?

**(2 points possible) What is the class relationship “has a relationship (composition)” , “is a relationship (inheritance)” or both?**

+ Inheritance: SavingsAccount and CheckingAccount inherit from BankAccount.
+ Composition: A Customer "has a" BankAccount.

**4. (4 points possible) Jot down ideas what each class looks like. Then draw a UML diagram for all classes using correct symbols and class relationship.**

Added a quick mock up of a UML for us to work on. Just need to make sure that we are doing it correctly and have everything there. I think it together really quick so there are probably many improvements to be made.
