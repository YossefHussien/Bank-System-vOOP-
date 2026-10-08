#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowFindUserScreen()
    {
        string Username = "";
        _DrawScreenHeader("Find User Screen");
        cout << "Please Enter Username : ";
        Username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, please choose another one: ";
            Username = clsInputValidate::ReadString();

        }

        clsUser User1 = clsUser::Find(Username);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found\n";
        }
        else
        {
            cout << "\nUser Was Not Found\n";
        }

        _PrintUser(User1);



    }


};
