#pragma once
class clsShowFindUserScreen
{

private:

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

public:

    static void ShowFindUserScreen() {

        clsScreen::DrawHeader();

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t        Find User" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;

        string UserName = "";
        UserName = clsInputValidate::ReadString("Enter User Name: ");

        while (!clsUser::isUserExist(UserName))
        {

            cout << "\nUser Name is Not Found!" << endl;
            UserName = clsInputValidate::ReadString("Enter Another User Name: ");

        }

        clsUser User = clsUser::Find(UserName);

        if (User.UserName() == "Admin") {
            cout << "\n\n========================================================" << endl;
            cout << "\nYou Cannot Show this User!" << endl;
            cout << "\n========================================================" << endl;
            return;
        }

        if (!User.isEmpty()) {
            cout << "\nUser Found!\n";
        }
        else {
            cout << "\nUser Not Found!\n";
        }

        _PrintUser(User);

    }

};

