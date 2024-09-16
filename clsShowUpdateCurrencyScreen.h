#pragma once
class clsShowUpdateCurrencyScreen
{

	static void _PrintCurrency(clsCurrency Curr) {

		cout << "Currency Card: " << endl;
		cout << "_____________________________\n" << endl;
		cout << "Country  : " << Curr.CountryName() << endl;
		cout << "Code     : " << Curr.CountryCode() << endl;
		cout << "Name     : " << Curr.CurrencyName() << endl;
		cout << "Rate(1$) : " << Curr.Rate() << endl;
		cout << "_____________________________" << endl;

	}

public:

	static void ShowUpdateCurrencyScreen() {

		clsScreen::DrawHeader();

		cout << endl;
		cout << setw(37) << left << "" << "________________________________________________\n" << endl;
		cout << setw(30) << left << "" << "\t\t\t        Update Currency" << endl;
		cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;


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

		_PrintCurrency(Curr);

		char Answer = 'Y';
		cout << "\nAre you sure you want to update this currency Rate? (Y/N)? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {

			float Rate = 0;
			cout << "\n\nUpdate Currency Rate: " << endl;
			cout << "________________________________" << endl;
			cout << "\nEnter New Rate: ";
			cin >> Rate;
			Curr.UpdateRate(Rate);
			cout << "Currency Rate Updated Successfully!" << endl;
			_PrintCurrency(Curr);

		}

	}

};

