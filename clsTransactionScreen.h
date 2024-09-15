#pragma once

#include "clsTotalBalancesScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

class clsTransactionScreen
{

private:

	static void ResetScreen() {
		system("cls");
	}

	enum enTransMenuOptions { Deposit = 1, Withdraw = 2, TotalBalances = 3, MainMenu = 4 };

	static short _ReadTransMenuOptions() {

		cout << setw(32) << left << "" << "\tChoose what do you want to do [1] to [4]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 4, "", "Enter Number between 1 and 4: ");
		return choice;
	}

	static void _GoBackToTransMenu() {
		cout << endl;
		cout << setw(32) << left << "" << "\tPress any key to return to Transaction Menu...";
		system("pause>0");
		ShowTranactionMenuScreen();
	}

	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithDrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ApplyChoices(enTransMenuOptions Choice) {

		switch (Choice)
		{
		case clsTransactionScreen::Deposit:
			ResetScreen();
			_ShowDepositScreen();
			_GoBackToTransMenu();
			break;
		case clsTransactionScreen::Withdraw:
			ResetScreen();
			_ShowWithDrawScreen();
			_GoBackToTransMenu();
			break;
		case clsTransactionScreen::TotalBalances:
			ResetScreen();
			_ShowTotalBalancesScreen();
			_GoBackToTransMenu();
			break;
		case clsTransactionScreen::MainMenu:
			break;
		default:
			break;
		}

	}

public:

	static void ShowTranactionMenuScreen() {

		ResetScreen();

		clsScreen::DrawHeader();

		if (!clsScreen::CheckAccessRights(clsUser::enPermission::pTransaction))
			return;

		cout << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t               Transacton Menu                " << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t\t   [1] Deposit." << endl;
		cout << setw(32) << left << "" << "\t\t   [2] Withdraw." << endl;
		cout << setw(32) << left << "" << "\t\t   [3] Total Balances." << endl;
		cout << setw(32) << left << "" << "\t\t   [4] Main Menu." << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;

		_ApplyChoices((enTransMenuOptions)_ReadTransMenuOptions());

	}

};

