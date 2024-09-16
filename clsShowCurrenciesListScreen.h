#pragma once
class clsShowCurrenciesListScreen
{

    static void _PrintCurrencyRecord(clsCurrency Curr) {

        cout << setw(10) << left << "" << "| " << left << setw(30) << Curr.CountryName();
        cout << "| " << left << setw(10) << Curr.CountryCode();
        cout << "| " << left << setw(30) << Curr.CurrencyName();
        cout << "| " << left << setw(10);
        printf("%0.3f", Curr.Rate());

    }

public:

	static void ShowCurrenciesListScreen() {

		clsScreen::DrawHeader();

        vector <clsCurrency> vCurr = clsCurrency::GetCurrencyList();

        cout << endl;
        cout << setw(10) << left << "" << "\t\t\t\t      Currency List (" << vCurr.size() << ") Client(s)" << endl;
        cout << setw(10) << left << "" << "________________________________________________";
        cout << "________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(10) << "Rate" << endl;
        cout << setw(10) << left << "" << "________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vCurr.size() == 0)
            cout << "\t\t\t\tNo Countries Available in the System!" << endl;
        else {

            for (clsCurrency& Curr : vCurr) {

                _PrintCurrencyRecord(Curr);
                cout << endl;

            }
            cout << setw(10) << left << "" << "________________________________________________";
            cout << "________________________________________________\n" << endl;
        }

	}

};

