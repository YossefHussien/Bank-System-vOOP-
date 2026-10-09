#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsString.h"
#include <vector>
#include "clsPerson.h"
using namespace std;


class clsBankClient : public clsPerson
{
	enum enMode{EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4]
			, vClientData[5], stod(vClientData[6]));

	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line.empty() || Line.find_first_not_of(" \t\r\n") == string::npos)
					continue;

				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	
	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out);
		
		if (Myfile.is_open())
		{
			string DataLine;
			for (clsBankClient C : vClients)
			{
				if (C._MarkedForDelete == false)
				{
					DataLine = _ConverClientObjectToLine(C);
					Myfile << DataLine << endl;
				}
			}
			Myfile.close();
		}

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

	}

    void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));

	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetExactSystemDateTimeString() + Seperator;
		TransferLogRecord += _AccountNumber + Seperator;
		TransferLogRecord += DestinationClient._AccountNumber + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(_AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient._AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TransferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TransferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TransferLogRecord.DestinedAccountNumber = vTrnsferLogRecordLine[2];
		TransferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TransferLogRecord.SourceClientBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TransferLogRecord.DestinedClientBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TransferLogRecord.Username = vTrnsferLogRecordLine[6];

		return TransferLogRecord;

	}




public :

	struct stTransferLogRecord
	{
		string DateTime;
		string Username;
		string SourceAccountNumber;
		string DestinedAccountNumber;
		float Amount;
		float SourceClientBalanceAfter;
		float DestinedClientBalanceAfter;
	};


	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) 
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountBalance = AccountBalance;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
	}

	bool IsEmpty()
	{
		return (enMode::EmptyMode == _Mode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)                                                                  
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{



		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExist = 2};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{

			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}
		case enMode::AddNewMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExist;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

		}


		}



	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "",0);
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}

		}
		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static  vector <clsBankClient> GetClientList()
	{
		return _LoadClientsDataFromFile();
}

	static double GetTotalBalances()
	{
		double Total = 0;
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			Total += C.AccountBalance;
	}
	
		return Total;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}


	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount <= 0 || Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);

		return true;
	}


	static  vector <stTransferLogRecord> GetTransfersLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}

};

