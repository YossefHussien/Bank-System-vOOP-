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

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}

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

