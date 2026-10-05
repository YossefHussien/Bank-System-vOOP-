#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"
#include "clsString.h"

class clsInputValidate
{
public:

    static bool IsPositive(int Number)
    {
        return Number > 0;
    }

    static bool IsNegative(int Number)
    {
        return Number < 0;
    }

    static bool IsZero(int Number)
    {
        return Number == 0;
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }

    static bool IsNumberBetween(short Number, short From, short To)
    {
        return Number >= From && Number <= To;
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        return Number >= From && Number <= To;
    }

    static bool IsNumberBetween(float Number, float From, float To)
    {
        return Number >= From && Number <= To;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            )
        {
            return true;
        }


        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            )
        {
            return true;
        }

        return false;
    }

    static bool IsEqual(int Number1, int Number2)
    {
        return Number1 == Number2;
    }

    static bool IsNumber(string Text)
    {
        for (char c : Text)
        {
            if (!isdigit(c))
                return false;
        }
        return !Text.empty();
    }

    static bool IsLetter(char Character)
    {
        return isalpha(Character);
    }

    static bool IsDigit(char Character)
    {
        return isdigit(Character);
    }

    static bool IsUpperCase(char Character)
    {
        return isupper(Character);
    }

    static bool IsLowerCase(char Character)
    {
        return islower(Character);
    }

    static bool IsSpecialCharacter(char Character)
    {
        return !isalpha(Character) && !isdigit(Character);
    }

    static bool IsEmpty(string Text)
    {
        return Text.empty();
    }

    static bool IsDivisibleBy(int Number, int Divisor)
    {
        return Divisor != 0 && Number % Divisor == 0;
    }

    static int ReadIntNumber()
    {
        int Number;

        cin >> Number;
        while (cin.fail())
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter again:" << endl;
            cin >> Number;
        }
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static int ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        short Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadShortNumber();
        }
        return Number;
    }

    static float ReadFloatNumber(string Message = "Please enter a number: ")
    {
        float Number;
        cout << Message;
        cin >> Number;

        while (cin.fail())
        {
            // User didn't enter a number
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Please enter a valid one:" << endl;
            cin >> Number;
        }

        return Number;
    }

    static float ReadShortNumber(string Message = "Please enter a number: ")
    {
        short Number;
        cout << Message;
        cin >> Number;

        while (cin.fail())
        {
            // User didn't enter a number
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Please enter a valid one:" << endl;
            cin >> Number;
        }

        return Number;
    }

    static double ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        float Number = ReadFloatNumber();

        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadDoubleNumber();
        }
        return Number;
    }

    static float ReadDoubleNumber()
    {
        double Number;
        cin >> Number;

        while (cin.fail())
        {
            // User didn't enter a number
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Please enter a valid one:" << endl;
            cin >> Number;
        }

        return Number;
    }

    static  bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDoubleNumber();

        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadDoubleNumber();
        }
        return Number;
    }

   static string ReadString()
    {
        string Text;
        getline(cin >> ws, Text);
        return Text;
    }
};

