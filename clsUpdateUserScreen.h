#pragma once
class clsUpdateUserScreen
{

private:

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

        cout << "\nShow Login Register Screen? (Y/N)? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermission::pLoginRegister;
        }


        return Permission;

    }

public:

    static void ShowUpdateUserScreen() {

        clsScreen::DrawHeader();

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t       Update User" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;


        string UserName = "";
        UserName = clsInputValidate::ReadString("Enter User Name: ");

        while (!clsUser::isUserExist(UserName))
        {

            cout << "\nUser Name is Not Found!" << endl;
            UserName = clsInputValidate::ReadString("Enter Another User Name: ");

        }

        clsUser User = clsUser::Find(UserName);
        /*if (User.UserName() == "Admin") {
            cout << "\n\n========================================================" << endl;
            cout << "\nYou Cannot Update this User!" << endl;
            cout << "\n========================================================" << endl;
            return;
        }*/
        _PrintUser(User);
        cout << "\nUpdate User Info: " << endl;
        cout << "---------------------------------------" << endl;
        _ReadUserInfo(User);
        clsUser::enSaveResult SaveResult = User.Save();


        switch (SaveResult)
        {
        case clsUser::svFailed:
            cout << "\nError, Account Was Not Saved Because it is Empty!" << endl;
            break;

        case clsUser::svSucceeded:
            cout << "\nAccount Saved Successfully!" << endl;
            break;
        }

        _PrintUser(User);

    }

};

