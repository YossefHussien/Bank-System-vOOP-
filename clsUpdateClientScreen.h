#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name:";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name:";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email:";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone:";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode:";
		Client.PinCode = clsInputValidate::ReadString();

		Client.AccountBalance = clsInputValidate::ReadFloatNumber("Enter Account Balance:");
	}

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
	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("Update Client Screen");
		string AccountNumber = "";
		cout << "Please Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Please enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}


		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		cout << "Client Card : \n";
		_PrintClient(Client1);

		cout << "\nAre you sure you want to delete this client? y/n\n";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Client Info: ";
			cout << "\n________________________________\n";

			_ReadClientInfo(Client1);

			clsBankClient::enSaveResults SaveResults;

			SaveResults = Client1.Save();

			switch (SaveResults)
			{
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError Account was not saved because it's empty.\n";
				break;
			}
			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated SuccessFully.\n";
				break;
			}

			}
		}
		
	}
};

