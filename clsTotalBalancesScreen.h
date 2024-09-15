#pragma once
class clsTotalBalancesScreen
{

private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client) {

        cout << setw(40) << left << "" << "| " << left << setw(10) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.GetBalance();

    }

public:

    static void ShowTotalBalances() {

        clsScreen::DrawHeader();

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << endl;
        cout << setw(40) << left << "" << "________________________________________________\n" << endl;
        cout << setw(30) << left << "" << "\t\t\t      Total Balances" << endl;
        cout << setw(40) << left << "" << "________________________________________________\n\n\n" << endl;

        cout << setw(40) << left << "" << "| " << left << setw(10) << "Acc NO.";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance" << endl;
        cout << setw(40) << left << "" << "___________________________________________\n\n";

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << setw(40) << left << "" << "Clients Available in the System!" << endl;
        else {

            for (clsBankClient& Client : vClients) {

                _PrintClientRecordBalanceLine(Client);
                cout << endl;

            }
            cout << setw(40) << left << "" << "___________________________________________\n\n";
        }

        cout << setw(40) << left << "" << "Total Balances is: " << TotalBalances << endl;
        cout << setw(40) << left << "" << "( " << clsUtils::NumberToText(TotalBalances) << ")" << endl;

    }

};

