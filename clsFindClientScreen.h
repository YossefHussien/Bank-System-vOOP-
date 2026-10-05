#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsFindClientScreen : protected clsScreen
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
	static void ShowFindClientScreen()
	{
		string AccountNumber = "";
		_DrawScreenHeader("Find Client Screen");
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, please choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found\n";
		}
		else
		{
			cout << "\nClient Was Not Found\n";
		}

		_PrintClient(Client1);
	}

};