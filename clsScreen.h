#pragma once
#include "Global.h"
#include "clsUser.h"
#include "../OOP_C++/clsDate.h"
class clsScreen
{

public:

	static void DrawHeader() {

		cout << endl;
		cout << "User: " << CurrentUser.UserName() << endl;
		cout << "Date: " << clsDate::DateToString(clsDate()) << endl;

	}

	static bool CheckAccessRights(clsUser::enPermission Permission) {

		if (!CurrentUser.CheckAccessPermissions(Permission)) {

			cout << setw(37) << left << "" << "_____________________________________\n" << endl;
			cout << setw(37) << left << "" << "\t       Access Denied!" << endl;
			cout << setw(37) << left << "" << "_____________________________________\n" << endl;
			return false;
		}
		else
			return true;

	}

};

