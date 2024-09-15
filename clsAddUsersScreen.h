#pragma once
#include "clsUser.h"
class clsAddUsersScreen
{

    static void _ReadUserInfo(clsUser& User) {

        User.SetFirstName(clsInputValidate::ReadString("\nEnter First Name: "));
        User.SetLastName(clsInputValidate::ReadString("\nEnter Last Name: "));
        User.SetEmail(clsInputValidate::ReadString("\nEnter Email: "));
        User.SetPhoneNumber(clsInputValidate::ReadString("\nEnter Phone Number: "));
        User.SetPassword(clsInputValidate::ReadString("\nEnter Password: "));
        User.SetPermission(_SetPermissions());

    }

    static void _PrintUser(clsUser User) {

        cout << "\nUser Card: " << endl;
        cout << "---------------------------------------" << endl;
        cout << "User Name  : " << User.UserName() << endl;
        cout << "First Name : " << User.FirstName() << endl;
        cout << "Last Name  : " << User.LastName() << endl;
        cout << "Full Name  : " << User.FullName() << endl;
        cout << "Email      : " << User.Email() << endl;
        cout << "Phone      : " << User.PhoneNumber() << endl;
        cout << "Password   : " << User.Password() << endl;
        cout << "Permissions: " << User.Permission() << endl;
        cout << "---------------------------------------" << endl;

    }

    static int _SetPermissions() {

        int Permission = 0;
        char Answer = 'n';

        cout << "\nEnter Permissions:" << endl;

        cout << "Do You want to Give full Access? (Y/N)? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            return -1;
        }

        cout << "Do You want to Give Access To: " << endl;
        cout << "\nShow Client List? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pShow;
        }

        cout << "\nAdd New Client? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pAdd;
        }

        cout << "\nDelete Client? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pDelete;
        }

        cout << "\nUpdate Client? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pUpdate;
        }

        cout << "\nFind Client? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pFind;
        }

        cout << "\nTransaction? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pTransaction;
        }


        cout << "\nManage Users? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pManageUsers;
        }

        return Permission;

    }

public:

    static void ShowAddNewUserScreen() {

        clsScreen::DrawHeader();

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t      Add New User" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;

        string UserName = "";
        UserName = clsInputValidate::ReadString("Enter User Name: ");

        while (clsUser::isUserExist(UserName))
        {

            cout << "\nThis User Name Already Exist!" << endl;
            UserName = clsInputValidate::ReadString("Enter Another User Name: ");

        }

        clsUser User = clsUser::CreateNewUserObject(UserName);
        cout << "\nAdd New User: " << endl;
        cout << "---------------------------------------" << endl;
        _ReadUserInfo(User);
        clsUser::enSaveResult Result = User.Save();

        switch (Result)
        {
        case clsUser::svFailedAccNumExist:
            cout << "\nError, Account Was Not Added because User Name Already Exist!" << endl;
            break;

        case clsUser::svSucceeded:
            cout << "\nAccount Created Successfully!" << endl;
            break;
        }

        _PrintUser(User);

    }


};

