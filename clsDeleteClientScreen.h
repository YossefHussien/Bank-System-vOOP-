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

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}

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

