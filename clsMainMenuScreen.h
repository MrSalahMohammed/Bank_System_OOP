#pragma once
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsBankClient.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsShowLoginRegisterScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsCurrency.h"
#include "clsShowCurrencyExchangeScreen.h"
#include "clsScreen.h"
#include <iomanip>
#include <iostream>
class clsMainMenuScreen : public clsScreen
{

private:

	static void ResetScreen() {
		system("cls");
	}

	enum enMainMenuOptions { Show = 1, Add = 2, Delete = 3, Update = 4,
		Find = 5, Transaction = 6, ManageUsers = 7, LoginRegister = 8, CurrencyExchange = 9, Logout = 10 };

	static short _ReadMainMenuOptions() {

		cout << setw(32) << left << "" << "\tChoose what do you want to do [1] to [10]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 10, "", "Enter Number between 1 and 10: ");
		return choice;
	}

	static void _GoBackToMainMenu() {
		cout << endl;
		cout << setw(32) << left << "" << "\tPress any key to return to Main Menu...";
		system("pause>0");
		MainMenu();
	}

	static void _ShowAllClientsScreen() {
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddClientsScreen() {
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientsScreen() {
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientsScreen() {
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientsScreen() {
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionScreen() {
		clsTransactionScreen::ShowTranactionMenuScreen();
	}

	static void _ShowManageUsersScreen() {
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	static void _ShowLogoutScreen() {
		CurrentUser = clsUser::Find("", "");
	}

	static void _ShowLoginRegisterScreen() {
		clsShowLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen() {
		clsShowCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	static void _PerformMainMenuOptions(enMainMenuOptions Choice) {

		switch (Choice)
		{
		case clsMainMenuScreen::Show:
			ResetScreen();
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::Add:
			ResetScreen();
			_ShowAddClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::Delete:
			ResetScreen();
			_ShowDeleteClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::Update:
			ResetScreen();
			_ShowUpdateClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::Find:
			ResetScreen();
			_ShowFindClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::Transaction:
			ResetScreen();
			_ShowTransactionScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::ManageUsers:
			ResetScreen();
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::LoginRegister:
			ResetScreen();
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::CurrencyExchange:
			ResetScreen();
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::Logout:
			ResetScreen();
			_ShowLogoutScreen();
			break;
		default:
			break;
		}

	}

public:

	static void MainMenu() {

		ResetScreen();
		DrawHeader();
		cout << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t                  Main Menu                   " << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t\t   [1] Show Clients List." << endl;
		cout << setw(32) << left << "" << "\t\t   [2] Add New Client." << endl;
		cout << setw(32) << left << "" << "\t\t   [3] Delete Client." << endl;
		cout << setw(32) << left << "" << "\t\t   [4] Update Client." << endl;
		cout << setw(32) << left << "" << "\t\t   [5] Find Client." << endl;
		cout << setw(32) << left << "" << "\t\t   [6] Tranaction." << endl;
		cout << setw(32) << left << "" << "\t\t   [7] Manage Users." << endl;
		cout << setw(32) << left << "" << "\t\t   [8] Login Register." << endl;
		cout << setw(32) << left << "" << "\t\t   [9] Currency Exchange." << endl;
		cout << setw(32) << left << "" << "\t\t   [10] Logout." << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		
		_PerformMainMenuOptions((enMainMenuOptions)_ReadMainMenuOptions());

	}

};

