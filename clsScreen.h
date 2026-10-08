#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{

protected:

    static const short _ScreenIndent = 37;
    static const short _ContentWidth = 42;

    static void _PrintIndent()
    {
        cout << setw(_ScreenIndent) << left << "";
    }

    static void _DrawHorizontalLine(char LineChar = '=')
    {
        _PrintIndent();
        cout << string(_ContentWidth, LineChar) << "\n";
    }

    static void _PrintCenteredText(string Text)
    {
        short Padding = (_ContentWidth - (short)Text.length()) / 2;
        if (Padding < 0)
            Padding = 0;

        _PrintIndent();
        cout << string(Padding, ' ') << Text << "\n";
    }

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n\n";
        _DrawHorizontalLine('=');
        _PrintCenteredText(Title);

        if (SubTitle != "")
        {
            _PrintCenteredText(SubTitle);
        }

        _DrawHorizontalLine('=');

        _PrintIndent();
        if (CurrentUser.UserName != "")
        {
            cout << "User: " << left << setw(18) << CurrentUser.UserName;
        }
        else
        {
            cout << left << setw(24) << "";
        }
        cout << "Date: " << clsDate::DateToString(clsDate::GetSystemDate()) << "\n\n";
    }

    static void _DrawMenueHeader(string Title)
    {
        _DrawHorizontalLine('=');
        _PrintCenteredText(Title);
        _DrawHorizontalLine('=');
    }

    static void _DrawMenueOption(short Number, string Option)
    {
        _PrintIndent();
        cout << "   [" << Number << "]  " << Option << "\n";
    }

    static void _DrawMenueFooter()
    {
        _DrawHorizontalLine('=');
        cout << "\n";
    }

    static void _PrintChoicePrompt(short From, short To)
    {
        _PrintIndent();
        cout << "Choose what do you want to do? [" << From << " to " << To << "]? ";
    }

    static void _PrintGoBackMessage(string MenueName)
    {
        cout << "\n\n";
        _PrintIndent();
        cout << "Press any key to go back to " << MenueName << "...";
    }

    static void _DrawInfoCardHeader(string Title)
    {
        cout << "\n";
        cout << "  ------------------------------------------\n";
        cout << "  | " << left << setw(38) << Title << " |\n";
        cout << "  ------------------------------------------\n";
    }

    template <typename T>
    static void _DrawInfoCardLine(string Label, T Value)
    {
        ostringstream ValueStream;
        ValueStream << Value;

        cout << "  | " << left << setw(12) << Label
             << ": " << left << setw(24) << ValueStream.str() << " |\n";
    }

    static void _DrawInfoCardFooter()
    {
        cout << "  ------------------------------------------\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\n\n";
            _DrawHorizontalLine('=');
            _PrintCenteredText("Access Denied!");
            _PrintCenteredText("Contact your Admin.");
            _DrawHorizontalLine('=');
            cout << "\n";
            return false;
        }

        return true;
    }

};
