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

public:
	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;// this will exit the function and it will not continue
		}

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
		_PrintClient(Client1);

		cout << "\nAre you sure you want to update this client? y/n\n";
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

