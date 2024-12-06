# Minimum required CMake version
cmake_minimum_required(VERSION 3.26)

# Project name and language
project(cs162_group_banking_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Define executable and source files
add_executable(cs162_group_banking_project
        # Main entry point
        main.cpp
        
        # Core banking classes
        BankAccount.cpp
        BankAccountContainer.cpp
        
        # Account type implementations
        CheckingAccount.cpp
        CreditAccount.cpp
        SavingsAccount.cpp
        MMDA.cpp
        
        # Certificate of Deposit implementations
        OneYearCD.cpp
        ThreeMonthCD.cpp
        SixMonthCD.cpp
        
        # Base classes
        MoneyMarketBase.cpp
        
        # User interface
        menu.cpp
        
        # Customer management
        Customer.cpp)
