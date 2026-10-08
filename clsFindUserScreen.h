#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
    static void _PrintUser(clsUser User)
    {
        _DrawInfoCardHeader("User Card");
        _DrawInfoCardLine("First Name", User.FirstName);
        _DrawInfoCardLine("Last Name", User.LastName);
        _DrawInfoCardLine("Full Name", User.FullName());
        _DrawInfoCardLine("Email", User.Email);
        _DrawInfoCardLine("Phone", User.Phone);
        _DrawInfoCardLine("User Name", User.UserName);
        _DrawInfoCardLine("Password", User.Password);
        _DrawInfoCardLine("Permissions", User.Permissions);
        _DrawInfoCardFooter();
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
