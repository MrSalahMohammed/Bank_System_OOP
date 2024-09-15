#pragma once
class clsFindClientScreen
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

    static void ShowFindClientScreen() {

        clsScreen::DrawHeader();

        if (!clsScreen::CheckAccessRights(clsUser::enPermission::pFind))
            return;

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t        Find Client" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;

        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString("Enter Account Number: ");

        while (!clsBankClient::isClientExist(AccountNumber))
        {

            cout << "\nAccount Number is Not Found!" << endl;
            AccountNumber = clsInputValidate::ReadString("Enter Another Account Number: ");

        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.isEmpty()) {
            cout << "\nClient Found!\n";
        }
        else {
            cout << "\nClient Not Found!\n";
        }

        _PrintClient(Client);

    }

};

