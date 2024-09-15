#pragma once
#include "clsUser.h"
class clsShowAllUsersScreen
{

private:

    static void _PrintUserRecord(clsUser User) {

        cout << setw(10) << left << "" << "| " << left << setw(10) << User.UserName();
        cout << "| " << left << setw(20) << User.FullName();
        cout << "| " << left << setw(12) << User.PhoneNumber();
        cout << "| " << left << setw(25) << User.Email();
        cout << "| " << left << setw(10) << User.Password();
        cout << "| " << left << setw(12) << User.Permission();

    }

public:

    static void ShowUsersList() {

        clsScreen::DrawHeader();

        vector <clsUser> vUsers = clsUser::GetUsersList();

        cout << endl;
        cout << setw(10) << left << "" << "\t\t\t\t      User List (" << vUsers.size() << ") User(s)" << endl;
        cout << setw(10) << left << "" << "____________________________________________________";
        cout << "________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(10) << "UserName";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions" << endl;
        cout << setw(10) << left << "" << "____________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available in the System!" << endl;
        else {

            for (clsUser& User : vUsers) {

                if (User.UserName() == "Admin")
                    continue;

                _PrintUserRecord(User);
                cout << endl;

            }
            cout << setw(10) << left << "" << "____________________________________________________";
            cout << "________________________________________________\n" << endl;
        }

    }

};

