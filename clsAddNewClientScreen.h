#pragma once
class clsAddNewClientScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client) {

        Client.SetFirstName(clsInputValidate::ReadString("\nEnter First Name: "));
        Client.SetLastName(clsInputValidate::ReadString("\nEnter Last Name: "));
        Client.SetEmail(clsInputValidate::ReadString("\nEnter Email: "));
        Client.SetPhoneNumber(clsInputValidate::ReadString("\nEnter Phone Number: "));
        Client.SetPINCode(clsInputValidate::ReadString("\nEnter PIN: "));
        Client.SetBalance(clsInputValidate::ReadDblNumber("\nEnter Balance: "));

    }

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

    static void ShowAddNewClientScreen() {

        clsScreen::DrawHeader();

        if (!clsScreen::CheckAccessRights(clsUser::enPermission::pAdd))
            return;

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t      Add New Client" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;

        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString("Enter Account Number: ");

        while (clsBankClient::isClientExist(AccountNumber))
        {

            cout << "\nThis Account Number Already Exist!" << endl;
            AccountNumber = clsInputValidate::ReadString("Enter Another Account Number: ");

        }

        clsBankClient Client = clsBankClient::CreateNewClientObject(AccountNumber);
        cout << "\nAdd New Client: " << endl;
        cout << "---------------------------------------" << endl;
        _ReadClientInfo(Client);
        clsBankClient::enSaveResult Result = Client.Save();

        switch (Result)
        {
        case clsBankClient::svFailedAccNumExist:
            cout << "\nError, Account Was Not Added because Account Number Already Exist!" << endl;
            break;

        case clsBankClient::svSucceeded:
            cout << "\nAccount Created Successfully!" << endl;
            break;
        }

        _PrintClient(Client);

    }

};

