#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{

private:
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
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("Delete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};

