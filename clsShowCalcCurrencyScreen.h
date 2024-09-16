#pragma once
class clsShowCalcCurrencyScreen
{

	static void _PrintCurrency(clsCurrency Curr, string Message = "Currency Card: ") {

		cout << Message << endl;
		cout << "_____________________________\n" << endl;
		cout << "Country  : " << Curr.CountryName() << endl;
		cout << "Code     : " << Curr.CountryCode() << endl;
		cout << "Name     : " << Curr.CurrencyName() << endl;
		cout << "Rate(1$) : " << Curr.Rate() << endl;
		cout << "_____________________________" << endl;

	}

	static clsCurrency GetCurrency(string Message) {

		clsCurrency Curr = clsCurrency::GetEmptyCurrency();

		do
		{

			string Code;
			cout << Message;
			cin >> Code;

			Curr = clsCurrency::FindByCode(Code);

			if (Curr.isEmpty())
				cout << "\nCannot Find Currency!";

		} while (Curr.isEmpty());

		return Curr;

	}

	static void _PrintCalculateResults(float Amount, clsCurrency From, clsCurrency To) {

		_PrintCurrency(From, "\nConvert From: ");
		cout << endl;
		_PrintCurrency(To, "Convert To: ");

		float ResultAmount = From.ConvertToOtherCountry(Amount, To);

		cout << "\n\n" << Amount << " " << From.CountryCode() << " = " << ResultAmount << " " << To.CountryCode() << endl;

	}

public:

	static void ShowCalcCurrencyScreen() {

		char Continue = 'Y';

		while (Continue == 'Y' || Continue == 'y')
		{

			clsScreen::DrawHeader();

			cout << endl;
			cout << setw(37) << left << "" << "________________________________________________\n" << endl;
			cout << setw(30) << left << "" << "\t\t\t      Calculate Currency" << endl;
			cout << setw(37) << left << "" << "________________________________________________\n\n\n" << endl;
			
			clsCurrency From = GetCurrency("\nFrom: ");
			clsCurrency To = GetCurrency("\To: ");

			float Amount;
			cout << "\nEnter Amount: ";
			cin >> Amount;

			_PrintCalculateResults(Amount, From, To);
			
			cout << "\n\nDo you want to perform another Calculation? (Y/N)? ";
			cin >> Continue;

		}

		



	}

};

