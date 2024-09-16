#pragma once

#include "clsScreen.h"

class clsShowLoginRegisterScreen
{

private:

    static void _PrintLoginRecord(clsUser::stLoginRegisterRecord Record) {

        cout << setw(10) << left << "" << "| " << left << setw(25) << Record.DateTime;
        cout << "| " << left << setw(10) << Record.UserName;
        cout << "| " << left << setw(10) << Record.Password;
        cout << "| " << left << setw(12) << Record.Permissions;

    }

public:


	static void ShowLoginRegisterScreen() {

		clsScreen::DrawHeader();

        if (!clsScreen::CheckAccessRights(clsUser::enPermission::pLoginRegister))
            return;
        
		vector <clsUser::stLoginRegisterRecord> vLogin = clsUser::LoadDataLogFromFile();

        cout << endl;
        cout << setw(10) << left << "" << "\t\t\t\t         Login Register of Users" << endl;
        cout << setw(10) << left << "" << "____________________________________________________";
        cout << "________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions" << endl;
        cout << setw(10) << left << "" << "____________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vLogin.size() == 0)
            cout << "\t\t\t\tNo Users Available in the System!" << endl;
        else {

            for (clsUser::stLoginRegisterRecord& Record : vLogin) {

                if (Record.UserName == "Admin")
                    continue;

                _PrintLoginRecord(Record);
                cout << endl;

            }
            cout << setw(10) << left << "" << "____________________________________________________";
            cout << "________________________________________________\n" << endl;
        }

	}

};

