#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateRateScreen : protected clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:
   static void ShowUpdateRateScreen()
    {

        char Answer = 'n';
        float NewRate = 0;

            cout << "\nPlease Enter Currency Code: ";
            string CurrencyCode = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyExist(CurrencyCode))
            {
                cout << "\nCurrency is not found, choose another one : ";
                CurrencyCode = clsInputValidate::ReadString();
            }
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        
            cout << "\nAre you sure you want to update this rate? y/n? ";
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            { 
                cout << "\n\nUpdate Currency Rate : \n";
                cout << "-------------------------\n";
                NewRate = clsInputValidate::ReadFloatNumber("Enter New Rate : ");
                Currency.UpdateRate(NewRate);

                cout << "\nCurrency Rate Updated Successfully.\n";
                _PrintCurrency(Currency);
            }
            else
            {
                return;
            }


    }

};

