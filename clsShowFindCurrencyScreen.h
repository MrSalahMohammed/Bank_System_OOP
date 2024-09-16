#pragma once
class clsShowFindCurrencyScreen
{
	enum enCurrencyMode { Code = 1, Country = 2 };

	static int _ReadChoice() {

		int choice = clsInputValidate::ReadIntNumberBetween(1, 2, "Find by: [1] Code or [2] Country ? ", "Invalid Choice, Try again: ");
		return choice;

	}

	static void _PrintCurrency(clsCurrency Curr) {

		cout << "Currency Card: " << endl;
		cout << "_____________________________\n" << endl;
		cout << "Country  : " << Curr.CountryName() << endl;
		cout << "Code     : " << Curr.CountryCode() << endl;
		cout << "Name     : " << Curr.CurrencyName() << endl;
		cout << "Rate(1$) : " << Curr.Rate() << endl;
		cout << "_____________________________" << endl;

	}

	static void _FindCurrByCode() {

		clsCurrency Curr = clsCurrency::GetEmptyCurrency();

		do
		{

			string Code;
			cout << "\nPlease Enter CurrencyCode: ";
			cin >> Code;

			Curr = clsCurrency::FindByCode(Code);

			if (Curr.isEmpty())
				cout << "\nCannot Find Currency!";

		} while (Curr.isEmpty());

		cout << "\nCurrency Found!\n" << endl;

		_PrintCurrency(Curr);

	}

	static void _FindCurrByName() {

		clsCurrency Curr = clsCurrency::GetEmptyCurrency();

		do
		{

			string CountryName;
			cout << "\nPlease Enter Country Name: ";
			getline(cin >> ws, CountryName);

			Curr = clsCurrency::FindByCountry(CountryName);

			if (Curr.isEmpty())
				cout << "\nCannot Find Currency!";

		} while (Curr.isEmpty());

		cout << "\nCurrency Found!\n" << endl;

		_PrintCurrency(Curr);

	}

	static void _PerformAction(enCurrencyMode Mode) {

		switch (Mode)
		{
		case clsShowFindCurrencyScreen::Code:
			_FindCurrByCode();
			break;
		case clsShowFindCurrencyScreen::Country:
			_FindCurrByName();
			break;
		default:
			break;
		}

	}

public:

	static void ShowFindCurrencyScreen() {

		clsScreen::DrawHeader();

		cout << endl;
		cout << setw(37) << left << "" << "________________________________________________\n" << endl;
		cout << setw(30) << left << "" << "\t\t\t        Find Currency" << endl;
		cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;

		_PerformAction((enCurrencyMode)_ReadChoice());

	}

};

