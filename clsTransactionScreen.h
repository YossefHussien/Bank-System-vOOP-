#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"

using namespace std;

class clsTransactionScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4,eShowMainMenue = 5
    };

    static short ReadTransactionsMenueOption()
    {
        _PrintChoicePrompt(1, 5);
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        _PrintGoBackMessage("Transactions Menue");
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eShowMainMenue:
        {
           // do nothing, main screen will handle it.
        }
        }


    }



public:


    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("Transactions Screen");

        _DrawMenueHeader("TRANSACTIONS MENU");
        _DrawMenueOption(1, "Deposit");
        _DrawMenueOption(2, "Withdraw");
        _DrawMenueOption(3, "Total Balances");
        _DrawMenueOption(4, "Transfer");
        _DrawMenueOption(5, "Main Menue");
        _DrawMenueFooter();

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};
