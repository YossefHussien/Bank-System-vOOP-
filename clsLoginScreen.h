#pragma once

#include <iostream>
#include "clsScreen.h"
#include <fstream>
#include "clsDate.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    
  


    static bool _Login()
    {
        bool LoginFailed = false;
        short FailedLoginCount = 3;
        string Username, Password;
        
        do
        {
            if (LoginFailed)
            {
                FailedLoginCount--;
                cout << "\n";
                _PrintIndent();
                cout << "Invalid Username/Password!\n";
                _PrintIndent();
                cout << "You have " << FailedLoginCount << " trial(s) remaining\n\n";
            }

            if (FailedLoginCount == 0)
            {
                cout << "\n";
                _PrintIndent();
                cout << "Max Trials Reached, please try again later.\n\n";
                return false;
            }

            _PrintIndent();
            cout << "Enter Username: ";
            cin >> Username;

            _PrintIndent();
            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("Login Screen");
        return _Login();
        
    }

};
