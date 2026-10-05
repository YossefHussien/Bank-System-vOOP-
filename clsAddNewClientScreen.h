#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
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

	static void ShowAddNewClientScreen()
	{
		_DrawScreenHeader("Add New Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Already Exists, Please enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResults;

		SaveResults = NewClient.Save();

		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nClient Added SuccessFully\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFailedAccountNumberExist:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}

		}

	}

};

