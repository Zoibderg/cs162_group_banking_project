cmake_minimum_required(VERSION 3.26)
project(cs162_group_banking_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(cs162_group_banking_project
        main.cpp
        BankAccount.cpp
        BankAccountContainer.cpp
        CheckingAccount.cpp
        CreditAccount.cpp
        Customer.cpp
        menu.cpp
        MMDA.cpp
        SavingsAccount.cpp
        OneYearCD.cpp
        ThreeMonthCD.cpp
        SixMonthCD.cpp
        MoneyMarketBase.cpp)
