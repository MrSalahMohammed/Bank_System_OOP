#pragma once

#include "clsTotalBalancesScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsShowTransferScreen.h"
#include "clsShowTransferLogScreen.h"

class clsTransactionScreen
{

private:

	static void ResetScreen() {
		system("cls");
	}

	enum enTransMenuOptions { Deposit = 1, Withdraw = 2, TotalBalances = 3, Transfer = 4, TransferLog = 5, MainMenu = 6 };

	static short _ReadTransMenuOptions() {

		cout << setw(32) << left << "" << "\tChoose what do you want to do [1] to [6]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6, "", "Enter Number between 1 and 6: ");
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

	static void _ShowTransferScreen() {
		clsShowTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		clsShowTransferLogScreen::ShowTransferLogScreen();
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
		case clsTransactionScreen::Transfer:
			ResetScreen();
			_ShowTransferScreen();
			_GoBackToTransMenu();
			break;
		case clsTransactionScreen::TransferLog:
			ResetScreen();
			_ShowTransferLogScreen();
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
		cout << setw(32) << left << "" << "\t\t   [4] Transfer." << endl;
		cout << setw(32) << left << "" << "\t\t   [5] Transfer Log." << endl;
		cout << setw(32) << left << "" << "\t\t   [6] Main Menu." << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;

		_ApplyChoices((enTransMenuOptions)_ReadTransMenuOptions());

	}

};

