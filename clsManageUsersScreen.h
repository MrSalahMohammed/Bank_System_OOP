#pragma once

#include "clsShowAllUsersScreen.h"
#include "clsAddUsersScreen.h"
#include "clsShowDeleteUsersScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsShowFindUserScreen.h"
#include "clsUser.h"

class clsManageUsersScreen
{

	static void ResetScreen() {
		system("cls");
	}

	enum enUserMenuOptions {
		ShowUser = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4,
		FindUser = 5, MainMenu = 6
	};

	static short _ReadUserMenuOptions() {

		cout << setw(32) << left << "" << "\tChoose what do you want to do [1] to [6]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6, "", "Enter Number between 1 and 6: ");
		return choice;
	}

	static void _GoBackToUsersMenu() {
		cout << endl;
		cout << setw(32) << left << "" << "\tPress any key to return to User Menu...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _ShowAllUsersScreen() {
		clsShowAllUsersScreen::ShowUsersList();
	}

	static void _ShowAddUsersScreen() {
		clsAddUsersScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUsersScreen() {
		clsShowDeleteUsersScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsersScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUsersScreen() {
		clsShowFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformUserMenuOptions(enUserMenuOptions Choice) {

		switch (Choice)
		{
		case clsManageUsersScreen::ShowUser:
			ResetScreen();
			_ShowAllUsersScreen();
			_GoBackToUsersMenu();
			break;
		case clsManageUsersScreen::AddUser:
			ResetScreen();
			_ShowAddUsersScreen();
			_GoBackToUsersMenu();
			break;
		case clsManageUsersScreen::DeleteUser:
			ResetScreen();
			_ShowDeleteUsersScreen();
			_GoBackToUsersMenu();
			break;
		case clsManageUsersScreen::UpdateUser:
			ResetScreen();
			_ShowUpdateUsersScreen();
			_GoBackToUsersMenu();
			break;
		case clsManageUsersScreen::FindUser:
			ResetScreen();
			_ShowFindUsersScreen();
			_GoBackToUsersMenu();
			break;
		case clsManageUsersScreen::MainMenu:
			break;
		default:
			break;
		}

	}

public:

	static void ShowManageUsersScreen() {

		ResetScreen();

		clsScreen::DrawHeader();

		if (!clsScreen::CheckAccessRights(clsUser::enPermission::pManageUsers))
			return;

		cout << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t                Manage Users                  " << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t\t   [1] Show Users List." << endl;
		cout << setw(32) << left << "" << "\t\t   [2] Add New User." << endl;
		cout << setw(32) << left << "" << "\t\t   [3] Delete User." << endl;
		cout << setw(32) << left << "" << "\t\t   [4] Update User." << endl;
		cout << setw(32) << left << "" << "\t\t   [5] Find User." << endl;
		cout << setw(32) << left << "" << "\t\t   [6] Main Menu." << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;

		_PerformUserMenuOptions((enUserMenuOptions)_ReadUserMenuOptions());

	}

};

