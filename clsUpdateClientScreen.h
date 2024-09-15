#pragma once
class clsUpdateClientScreen
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

    static void _ReadClientInfo(clsBankClient& Client) {

        Client.SetFirstName(clsInputValidate::ReadString("\nEnter First Name: "));
        Client.SetLastName(clsInputValidate::ReadString("\nEnter Last Name: "));
        Client.SetEmail(clsInputValidate::ReadString("\nEnter Email: "));
        Client.SetPhoneNumber(clsInputValidate::ReadString("\nEnter Phone Number: "));
        Client.SetPINCode(clsInputValidate::ReadString("\nEnter PIN: "));
        Client.SetBalance(clsInputValidate::ReadDblNumber("\nEnter Enter Balance: "));

    }

public:

    static void ShowUpdateClientScreen() {

        clsScreen::DrawHeader();

        if (!clsScreen::CheckAccessRights(clsUser::enPermission::pUpdate))
            return;

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t       Update Client" << endl;
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
        cout << "\nUpdate Client Info: " << endl;
        cout << "---------------------------------------" << endl;
        _ReadClientInfo(Client);
        clsBankClient::enSaveResult SaveResult = Client.Save();


        switch (SaveResult)
        {
        case clsBankClient::svFailed:
            cout << "\nError, Account Was Not Saved Because it is Empty!" << endl;
            break;

        case clsBankClient::svSucceeded:
            cout << "\nAccount Saved Successfully!" << endl;
            break;
        }

        _PrintClient(Client);

    }


};

