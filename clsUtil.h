#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"
#include "clsString.h"

class clsUtil
{

public:
	static void Swap(int & Number1, int & Number2)
	{
		int Temp;
		Temp = Number1;
		Number1 = Number2;
		Number2 = Temp;
	}
	static void Swap(string & String1, string & String2)
	{
		string Temp;
		Temp = String1;
		String1 = String2;
		String2 = Temp;
	}
	static void Swap(double& Number1, double& Number2)
	{
		double Temp;
		Temp = Number1;
		Number1 = Number2;
		Number2 = Temp;
	}
	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate::SwapDates(Date1, Date2);
	}


	static void srand()
	{
		::srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		return  rand() % (To - From + 1) + From;
	}

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixChars = 5 };

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharType::MixChars:
		{
			int Random = RandomNumber(1, 2);

			if (Random == 1)
				return char(RandomNumber(97, 122));

			else
				return char(RandomNumber(65, 90)); 
		}
		return '\0';
		}
	}	

	 static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++) 
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Kay [" << i << "] : " << GenerateKey(CharType) << endl;
		}
	}


	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To) 
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, int NumberOfCharactars)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(CharType, NumberOfCharactars);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{ 
			Text[i] = char((int)Text[i] + EncryptionKey);

		}
		return Text; 
	}

	static string DecryptionText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
			
		}
		return Text; 
	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
		}
		return t;

	}

};

