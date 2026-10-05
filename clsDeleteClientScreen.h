#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}


public:

	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("Delete Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Please enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient ClientToDelete = clsBankClient::Find(AccountNumber);
		_PrintClient(ClientToDelete);

		cout << "\nAre you sure you want to delete this client? y/n\n";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (ClientToDelete.Delete())
			{
				cout << "\nClient Deleted Successfully.\n";
				_PrintClient(ClientToDelete);
			}
			else
			{
				cout << "\nError, Client Was Not Deleted.\n";
			}

		}
	}





};

