#pragma once
class clsDeleteClientScreen
{

private:

    static void _PrintClient(clsBankClient Client) {

        cout << "\nClient Card: " << endl;
        cout << "---------------------------------------" << endl;
        cout << "Acc. Number: " << Client.AccountNumber() << endl;
        cout << "First Name : " << Client.FirstName() << endl;
        cout << "Last Name  : " << Client.LastName() << endl;
        cout << "Full Name  : " << Client.FullName() << endl;
        cout << "Email      : " << Client.Email() << endl;
        cout << "Phone      : " << Client.PhoneNumber() << endl;
        cout << "Balance    : " << Client.GetBalance() << endl;
        cout << "---------------------------------------" << endl;

    }

public:

    static void ShowDeleteClientScreen() {

        clsScreen::DrawHeader();

        if (!clsScreen::CheckAccessRights(clsUser::enPermission::pDelete))
            return;

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t       Delete Client" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;


        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString("Enter Account Number: ");

        while (!clsBankClient::isClientExist(AccountNumber))
        {

            cout << "\nAccount Number is Not Found!" << endl;
            AccountNumber = clsInputValidate::ReadString("Enter Another Account Number: ");

        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        char DeleteOrNot = 'Y';
        cout << "\nAre you sure you want to delete this client? (Y/N)? ";
        cin >> DeleteOrNot;

        if (DeleteOrNot == 'Y' || DeleteOrNot == 'y') {


            if (Client.Delete()) {
                cout << "\nAccount Deleted Successfully!" << endl;
                _PrintClient(Client);
            }
            else {
                cout << "\nAccount was NOT Deleted!" << endl;
            }

        }


    }

};

