#include "Account.h"
#include<iostream>

Account::Account() : balance{0}
{
    
}

void Account::display(void)
{
    std::cout << "Balance: " << balance << std::endl;
}

void Account::deposit(double amount)
{
    balance += amount;
    std::cout << "Deposit Succeeded" << std::endl;
}

void Account::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        std::cout << "Withdraw Succeeded" << std::endl;
    }
    else
    {
        std::cout << "Withdraw Failed" << std::endl;
    }
    
}

double Account::getBalance()
{
    return balance;
}