#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"

class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

    static void _DrawTableLine()
    {
        cout << setw(25) << left << "" << "------------------------------------------------------------------------\n";
    }

public:

    static void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "Balances List Screen";
        string SubTitle = "(" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n";
        _DrawTableLine();

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance" << "|\n";
        _DrawTableLine();

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\n\t\t\t\tNo Clients Available In the System!\n";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        _DrawTableLine();

        cout << "\n";
        cout << setw(25) << left << "" << "Total Balances = " << TotalBalances << endl;
        cout << setw(25) << left << "" << "( " << clsUtil::NumberToText((int)TotalBalances) << ")\n";
    }

};
