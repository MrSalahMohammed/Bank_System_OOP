#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsMainMenuScreen.h"
#include "Global.h"
#include "clsScreen.h"
using namespace std;
class clsShowLoginScreen : public clsScreen
{

private:

	static bool _Login() {

		string UserName, Password;
		bool LoginFailed = false;
		int LoginTimes = 0;

		do
		{
			
			if (LoginFailed) {
				cout << "\nInvalid UserName/Password!" << endl;
				LoginTimes++;
				cout << "You have " << (3 - LoginTimes) << " Trial(s) to login" << endl;
			}

			if (LoginTimes == 3) {
				cout << "System Locked!" << endl;
				return false;
			}
			
			cout << "\nEnter UserName: ";
			cin >> UserName;

			cout << "\nEnter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.isEmpty();

		} while (LoginFailed && LoginTimes < 3);

		CurrentUser.SaveLog();
		clsMainMenuScreen::MainMenu();
		return true;

	}

public:

	static bool Login() {

		system("cls");
		DrawHeader();
		cout << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		cout << setw(32) << left << "" << "\t                    Login                     " << endl;
		cout << setw(32) << left << "" << "\t==============================================" << endl;
		return _Login();
	}

};

