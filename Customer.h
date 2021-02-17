#pragma once

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

class Customer
{
private:
    string name;
    string username;
    string password;

public:
    Customer(string name, string username, string password);

    Account acc;

    string getName();
    string getUsername();
    string getPassword();
    double getBalance();
};