#pragma once
#include "clsCurrency.h"
#include "clsShowCurrenciesListScreen.h"
#include "clsShowFindCurrencyScreen.h"
#include "clsShowUpdateCurrencyScreen.h"
#include "clsShowCalcCurrencyScreen.h"
class clsShowCurrencyExchangeScreen
{

private:

	static void ResetScreen() {
		system("cls");
	}

	static void _GoBackToCurrExMenu() {
		cout << endl;
		cout << setw(32) << left << "" << "\tPress any key to return to Currency Exchange Menu...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	enum enCurrencyMenuOptions { List = 1, Find = 2, Update = 3, calc = 4, MainMenu = 5 };

	static int _ReadCurrencyMenuOptions() {

		cout << setw(32) << left << "" << "\tChoose what do you want to do [1] to [5]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 5, "", "Enter Number between 1 and 5: ");
		return choice;

	}

	static void _ShowListCurrenciesScreen() {
		clsShowCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen() {
		clsShowFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen() {
		clsShowUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCalcCurrencyScreen() {
		clsShowCalcCurrencyScreen::ShowCalcCurrencyScreen();
	}

	static void _PerformCurrencyMenuOptions(enCurrencyMenuOptions Choice) {

		switch (Choice)
		{
		case clsShowCurrencyExchangeScreen::List:
			ResetScreen();
			_ShowListCurrenciesScreen();
			_GoBackToCurrExMenu();
			break;
		case clsShowCurrencyExchangeScreen::Find:
			ResetScreen();
			_ShowFindCurrencyScreen();
			_GoBackToCurrExMenu();
			break;
		case clsShowCurrencyExchangeScreen::Update:
			ResetScreen();
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrExMenu();
			break;
		case clsShowCurrencyExchangeScreen::calc:
			ResetScreen();
			_ShowCalcCurrencyScreen();
			_GoBackToCurrExMenu();
			break;
		case clsShowCurrencyExchangeScreen::MainMenu:
			break;
		}

	}

public:

	static void ShowCurrencyExchangeScreen() {

		ResetScreen();
		clsScreen::DrawHeader();
		cout << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t            Currency Exchange Menu            " << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t\t   [1] Show Currencies List." << endl;
		cout << setw(32) << left << "" << "\t\t   [2] Find Currency." << endl;
		cout << setw(32) << left << "" << "\t\t   [3] Update Rate." << endl;
		cout << setw(32) << left << "" << "\t\t   [4] Currency Calculator." << endl;
		cout << setw(32) << left << "" << "\t\t   [5] Main Menu." << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;

		_PerformCurrencyMenuOptions((enCurrencyMenuOptions)_ReadCurrencyMenuOptions());

	}

};

