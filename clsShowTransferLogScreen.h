#pragma once
class clsShowTransferLogScreen
{

    static void _PrintTransRecord(clsUser::stTransferRegisterRecord Record) {

        cout << setw(10) << left << "" << "| " << left << setw(25) << Record.DateTime;
        cout << "| " << left << setw(10) << Record.SourceAcc;
        cout << "| " << left << setw(10) << Record.DesAcc;
        cout << "| " << left << setw(10) << Record.Amount;
        cout << "| " << left << setw(10) << Record.SourceBalance;
        cout << "| " << left << setw(10) << Record.DesBalance;
        cout << "| " << left << setw(10) << Record.User;

    }

public:

	static void ShowTransferLogScreen() {

		clsScreen::DrawHeader();

        vector <clsUser::stTransferRegisterRecord> vTransLog = clsUser::LoadTransLogFromFile();

        cout << endl;
        cout << setw(10) << left << "" << "\t\t\t\t         Transfer Register" << endl;
        cout << setw(10) << left << "" << "____________________________________________________";
        cout << "________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acc";
        cout << "| " << left << setw(10) << "D.Acc";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(10) << "User" << endl;
        cout << setw(10) << left << "" << "____________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vTransLog.size() == 0)
            cout << "\t\t\t\tNo Users Available in the System!" << endl;
        else {

            for (clsUser::stTransferRegisterRecord& Record : vTransLog) {

                _PrintTransRecord(Record);
                cout << endl;

            }
            cout << setw(10) << left << "" << "____________________________________________________";
            cout << "________________________________________________\n" << endl;
        }

	}

};

