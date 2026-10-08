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
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;// this will exit the function and it will not continue
		}

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