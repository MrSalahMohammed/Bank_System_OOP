#pragma once
class clsShowDeleteUsersScreen
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

    static void ShowDeleteUserScreen() {

        clsScreen::DrawHeader();

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t       Delete User" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;


        string UserName = "";
        UserName = clsInputValidate::ReadString("Enter User Name: ");

        while (!clsUser::isUserExist(UserName))
        {

            cout << "\n User Name is Not Found!" << endl;
            UserName = clsInputValidate::ReadString("Enter Another User Name: ");

        }

        clsUser User = clsUser::Find(UserName);
        
        if (User.UserName() == "Admin") {
            cout << "\n\n========================================================" << endl;
            cout << "\nYou Cannot Delete this User!" << endl;
            cout << "\n========================================================" << endl;
            return;
        }

        _PrintUser(User);

        char DeleteOrNot = 'Y';
        cout << "\nAre you sure you want to delete this User? (Y/N)? ";
        cin >> DeleteOrNot;

        if (DeleteOrNot == 'Y' || DeleteOrNot == 'y') {


            if (User.Delete()) {
                cout << "\nAccount Deleted Successfully!" << endl;
                _PrintUser(User);
            }
            else {
                cout << "\nAccount was NOT Deleted!" << endl;
            }

        }


    }

};

