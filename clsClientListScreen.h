#pragma once
#include "clsScreen.h"
class clsClientListScreen
{

private:

    static void _PrintClientRecord(clsBankClient Client) {

        cout << setw(10) << left << "" << "| " << left << setw(10) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.PhoneNumber();
        cout << "| " << left << setw(25) << Client.Email();
        cout << "| " << left << setw(10) << Client.GetPINCode();
        cout << "| " << left << setw(12) << Client.GetBalance();

    }

public:

    static void ShowClientsList() {

        clsScreen::DrawHeader();

        if (!clsScreen::CheckAccessRights(clsUser::enPermission::pShow))
            return;

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << endl;
        cout << setw(10) << left << "" << "\t\t\t\t      Client List (" << vClients.size() << ") Client(s)" << endl;
        cout << setw(10) << left << "" << "________________________________________________";
        cout << "________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(10) << "Acc NO.";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(10) << "PIN";
        cout << "| " << left << setw(12) << "Balance" << endl;
        cout << setw(10) << left << "" << "________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available in the System!" << endl;
        else {

            for (clsBankClient& Client : vClients) {

                _PrintClientRecord(Client);
                cout << endl;

            }
            cout << setw(10) << left << "" << "________________________________________________";
            cout << "________________________________________________\n" << endl;
        }

    }

};

