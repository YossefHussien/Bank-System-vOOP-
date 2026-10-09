#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"


class clsCurrencyExchangeScreen : protected clsScreen
{

    enum enCurrencyExchangeMenu
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short _ReadCurrencyExchangeMenueOption()
    {
        _PrintChoicePrompt(1, 5);
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToCurrencyExchangeMenu()
    {
        _PrintGoBackMessage("Currency Exchange Menu");
        system("pause>0");
        ShowCurrencyExchangeMenu();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        cout << "Find Currency code will be here";
    }

    static void _ShowUpdateRateScreen()
    {
        cout << "Update rate code will be here";
    }

    static void _ShowCurrencyCalcScreen()
    {
        cout << "Currency Calcluator code will be here";
    }

    static void _PerfromCurrencyExchangeMenuOption(enCurrencyExchangeMenu CurrencyExchangeOption)
    {
        switch (CurrencyExchangeOption)
        {
        case enCurrencyExchangeMenu::eListCurrencies:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyExchangeMenu::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyExchangeMenu::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyExchangeMenu::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalcScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyExchangeMenu::eMainMenu:
            break;

        }
    }


public:

    static void ShowCurrencyExchangeMenu()
    {
        system("cls");
        _DrawScreenHeader("Currency Exchange Main Screen");

        _DrawMenueHeader("urrency Exchange Menu");
        _DrawMenueOption(1, "List Currencies");
        _DrawMenueOption(2, "Find Currency");
        _DrawMenueOption(3, "Update Rate");
        _DrawMenueOption(4, "Currency Calculator");
        _DrawMenueOption(5, "Main Menu");
        _DrawMenueFooter();

        _PerfromCurrencyExchangeMenuOption((enCurrencyExchangeMenu)_ReadCurrencyExchangeMenueOption());
    }
};