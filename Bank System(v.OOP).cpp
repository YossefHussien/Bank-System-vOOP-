#include <iostream>
#include <limits>
#include <cctype>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "clsString.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

void ReadClientInfo(clsBankClient& Client)
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

void Update()
{
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
	Client1.Print();

	cout << "\n\nUpdate Client Info: ";
	cout << "\n________________________________\n";

	ReadClientInfo(Client1);

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

void AddNewClient()
{
	string AccountNumber = "";
	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();
	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount Number Already Exists, Please enter another one: ";
		AccountNumber = clsInputValidate::ReadString();
    }

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(NewClient);
	
	clsBankClient::enSaveResults SaveResults;
	
	SaveResults = NewClient.Save();

	switch (SaveResults)
	{
	case clsBankClient::enSaveResults::svSucceeded:
	{
		cout << "\nClient Added SuccessFully\n";
		NewClient.Print();
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

void DeleteClient()
{
	string AccountNumber = "";
	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount Number is not found, Please enter another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient ClientToDelete = clsBankClient::Find(AccountNumber);
	ClientToDelete.Print();

	cout << "\nAre you sure you want to delete this client? y/n\n";
	char Answer = 'n';
	cin >> Answer;

	if (Answer == 'y'|| Answer == 'Y')
	{
		if(ClientToDelete.Delete())
		{
			cout << "\nClient Deleted Successfully.\n";
			ClientToDelete.Print();
	    }
		else 
		{
			cout << "\nError, Client Was Not Deleted.\n";
		}
	
	}
}

void PrintClientRecordLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowClientsList()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{

			PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

}

void PrintClientRecordBalanceLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.AccountBalance;

}


void ShowTotalBalances()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientList();

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalances = clsBankClient::GetTotalBalances();

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}


int main()
{

	ShowTotalBalances();

}

