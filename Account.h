#pragma once

class Account
{
private:
    double balance;
public:
    Account();

    void display(void);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
};
