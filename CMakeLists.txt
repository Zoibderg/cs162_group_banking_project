cmake_minimum_required(VERSION 3.28)
project(cs162_group_banking_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(cs162_group_banking_project main.cpp
        menu.cpp
        menu.h
        BankAccountContainer.cpp
        Customer.cpp
        Customer.h
        BankAccount.cpp
        BankAccount.h
        CheckingAccount.cpp
        CheckingAccount.h
        SavingsAccount.cpp
        SavingsAccount.h
        CreditAccount.cpp
        CreditAccount.h
        Transaction.cpp
        Transaction.h
        CertificateOfDepositBase.cpp)
