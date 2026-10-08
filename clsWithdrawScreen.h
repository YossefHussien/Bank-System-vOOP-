#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        _DrawInfoCardHeader("Client Card");
        _DrawInfoCardLine("First Name", Client.FirstName);
        _DrawInfoCardLine("Last Name", Client.LastName);
        _DrawInfoCardLine("Full Name", Client.FullName());
        _DrawInfoCardLine("Email", Client.Email);
        _DrawInfoCardLine("Phone", Client.Phone);
        _DrawInfoCardLine("Acc. Number", Client.AccountNumber());
        _DrawInfoCardLine("Password", Client.PinCode);
        _DrawInfoCardLine("Balance", Client.AccountBalance);
        _DrawInfoCardFooter();
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);


        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDoubleNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};

