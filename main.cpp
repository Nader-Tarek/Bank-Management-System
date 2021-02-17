#include <iostream>
#include <string>
#include <vector>

#include "Customer.h"
#include "Account.h"
#include "SavingAccount.h"
#include "MoneyMarket.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "\n\nWelcome to our Bank Management System...\n\n";

    int selection {0};
    vector<Customer> customers;
    string tempName;
    string tempUsername;
    string tempPassword;

    //Outer loop for the first menu

    while (selection != 3)
    {
        cout << "1-New Customer\n2-Exisiting Customer\n3-Exit\n" << endl;
        cout << "Enter your selection: " << endl;
        cin >> selection;

        if (selection == 1) //New Customer Section
        {
            cout << "Enter you name: " << endl;
            cin >> tempName;
            cout << "Enter you username: " << endl;
            cin >> tempUsername;
            cout << "Enter you password: " << endl;
            cin >> tempPassword;
            Customer tempObj(tempName, tempUsername, tempPassword);
            customers.push_back(tempObj);
            cout << "Now you need yo login with your data..." << endl;

        }
        else if (selection == 2) //Existing Customer Section
        {
            cout << "Enter you username: " << endl;
            cin >> tempUsername;
            bool tempBool = false;
            int objectIndex{0};
            for (int i = 0; i < customers.size(); i++) //Checking if the username exists
            {
                if (tempUsername.compare(customers[i].getUsername()) == 0)
                {
                    objectIndex = i;
                    tempBool = true;
                    break;
                }
                
            }

            if (tempBool) //If the username exists logic
            {
                cout << "Enter you password: " << endl;
                cin >> tempPassword;
                if (tempPassword.compare(customers[objectIndex].getPassword()) == 0) // Validating the password
                {
                    // Functions menu

                    int selection2 {0};
                    while (selection != 4)
                    {
                        cout << "1-Display\n2-Deposit\n3-Withdraw\n4-Logout\n" << endl;
                        cin >> selection2;
                        if (selection2 == 1) // Displaying Section
                        {
                            cout << "Name: " << customers[objectIndex].getName() << endl;
                            cout << "Balance: " << customers[objectIndex].getBalance() << endl;
                        }
                        else if (selection2 == 2) // Deposit Section
                        {
                            double tempAmount;
                            cout << "Enter the amount you want to deposit: " << endl;
                            cin >> tempAmount;
                            customers[objectIndex].acc.deposit(tempAmount);
                        }
                        else if (selection2 == 3) // Withdraw Section
                        {
                            double tempAmount;
                            cout << "Enter the amount you want to withdraw: " << endl;
                            cin >> tempAmount;
                            customers[objectIndex].acc.withdraw(tempAmount);
                        }

                        else if (selection2 == 4) // Logout
                        {
                            cout << "Logging out..." << endl;
                            break;
                        }
                        else // If the use entered a wrong entry
                        {
                            cout << "Please try selecting a right numebr..." << endl;
                        }
                          
                    }
                    
                }
                else // if the user entered wrong password
                {
                    cout << "Wrong password..." << endl;
                }
                
            }
            else // if the username doesn't exist
            {
                cout << "Wrong username..." << endl;
            }
             
        }
        else if (selection == 3) // For exiting the program
        {
            cout << "Thanks for using our system..." << endl;
            return 0;
        }
        else // If the user entered wrong entry
        {
            cout << "Please try selecting a right numebr..." << endl;
        }
        
    }
    
    return 0;
}