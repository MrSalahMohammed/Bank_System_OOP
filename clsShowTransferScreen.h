#pragma once

class clsShowTransferScreen
{

    static void _PrintClient(clsBankClient Client) {

        cout << "\nClient Card: " << endl;
        cout << "---------------------------------------" << endl;
        cout << "Full Name  : " << Client.FullName() << endl;
        cout << "Acc. Number: " << Client.AccountNumber() << endl;
        cout << "Balance    : " << Client.GetBalance() << endl;
        cout << "---------------------------------------" << endl;

    }

public:

	static void ShowTransferScreen() {

        clsScreen::DrawHeader();

        cout << endl;
        cout << setw(37) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t          Transfer" << endl;
        cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;


		string From = clsInputValidate::ReadString("Enter Account to Transfer From: ");
        while (!clsBankClient::isClientExist(From))
        {

            cout << "\nAccount Number is Not Found!" << endl;
            From = clsInputValidate::ReadString("Enter Another Account Number: ");

        }
        clsBankClient Client1 = clsBankClient::Find(From);
        _PrintClient(Client1);


		string To = clsInputValidate::ReadString("Enter Account to Transfer To: ");
        while (!clsBankClient::isClientExist(To))
        {

            cout << "\nAccount Number is Not Found!" << endl;
            To = clsInputValidate::ReadString("Enter Another Account Number: ");

        }
        clsBankClient Client2 = clsBankClient::Find(To);
        _PrintClient(Client2);

        int Amount = clsInputValidate::ReadIntNumberBetween(0, Client1.Balance, "Enter Transfer Amount: ", "Amount exceeds Balance, Enter Another Amount: ");

        char Answer = 'Y';
        cout << "\nAre you want to perform this action? (Y/N)? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y') {

            if (Client1.Transfer(Amount, Client2)) {
                CurrentUser.SaveTransferLog(Client1, Client2, Amount);
                cout << "Transfer Done Successfully!" << endl;
            }
            else {
                cout << "Transfer Failed!" << endl;
            }
            _PrintClient(Client1);
            cout << endl;
            _PrintClient(Client2);
        }

	}

};

