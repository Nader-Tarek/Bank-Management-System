#include "Customer.h"

Customer::Customer(string name, string username, string password) 
    : name{name}, username{username}, password{password}
{

}

string Customer::getName()
{
    return name;
}

string Customer::getUsername()
{
    return username;
}

string Customer::getPassword()
{
    return password;
}

double Customer::getBalance()
{
    return acc.getBalance();
}