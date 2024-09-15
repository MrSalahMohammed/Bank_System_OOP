#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "../OOP_C++/clsDate.h"
#include "../OOP_C++/clsInputValidate.h"
#include "../OOP_C++/clsString.h"

class clsUser : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;
	bool _MarkForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {

		vector <string> User = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, User[0], User[1], User[2], User[3], User[4], User[5], stoi(User[6]));
	}

	static vector <clsUser> _LoadUserDataFromFile() {

		vector <clsUser> vUser;
		fstream UsersFile;

		UsersFile.open("Users.txt", ios::in);

		if (UsersFile.is_open()) {

			string Line;
			while (getline(UsersFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUser.push_back(User);
			}

			UsersFile.close();

		}

		return vUser;

	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#") {

		string stUserRecord = "";
		stUserRecord += User.FirstName() + Seperator;
		stUserRecord += User.LastName() + Seperator;
		stUserRecord += User.Email() + Seperator;
		stUserRecord += User.PhoneNumber() + Seperator;
		stUserRecord += User.UserName() + Seperator;
		stUserRecord += User.Password() + Seperator;
		stUserRecord += to_string(User.Permission());

		return stUserRecord;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers) {

		fstream UsersFile;

		UsersFile.open("Users.txt", ios::out);

		string DataLine;

		if (UsersFile.is_open()) {

			for (clsUser User : vUsers) {

				if (User.MarkForDelete() == false) {
					DataLine = _ConvertUserObjectToLine(User);
					UsersFile << DataLine << endl;
				}

			}

			UsersFile.close();

		}


	}

	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _Update() {

		vector <clsUser> vUser = _LoadUserDataFromFile();

		for (clsUser& User : vUser) {

			if (User.UserName() == UserName()) {

				User = *this;
				break;

			}

		}

		_SaveUsersDataToFile(vUser);


	}

	void _Add() {

		vector <clsUser> vUser = _LoadUserDataFromFile();
		clsUser User = *this;
		vUser.push_back(User);
		_SaveUsersDataToFile(vUser);

	}

	string _ConvertLogDataToLine(clsUser User, string Seperator = "#//#") {

		string LogData = "";
		LogData += clsDate::GetSystemDateTimeString() + Seperator;
		LogData += User.UserName() + Seperator;
		LogData += User.Password() + Seperator;
		LogData += to_string(User.Permission());

		return LogData;

	}

public:

	static enum enPermission {
		pAll = -1, pShow = 1, pAdd = 2, pDelete = 4,
		pUpdate = 8, pFind = 16, pTransaction = 32, pManageUsers = 64
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string UserName, string Password, int Permission) :
		clsPerson(FirstName, LastName, Email, Phone){

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;

	}

	bool isEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}

	void SetUserName(string UserName) {
		_UserName = UserName;
	}

	void SetPassword(string Password) {
		_Password = Password;
	}

	void SetPermission(int Permission) {
		_Permission = Permission;
	}

	string UserName() {
		return _UserName;
	}

	string Password() {
		return _Password;
	}

	int Permission() {
		return _Permission;
	}

	static clsUser Find(string UserName) {

		vector <clsUser> vUser;
		fstream UsersFile;

		UsersFile.open("Users.txt", ios::in);

		if (UsersFile.is_open()) {

			string Line;
			while (getline(UsersFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName() == UserName) {
					UsersFile.close();
					return User;
				}
				vUser.push_back(User);
			}

			UsersFile.close();

		}

		return _GetEmptyUserObject();

	}

	static clsUser Find(string UserName, string Password) {

		vector <clsUser> vUser;
		fstream UsersFile;

		UsersFile.open("Users.txt", ios::in);

		if (UsersFile.is_open()) {

			string Line;
			while (getline(UsersFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName() == UserName && User.Password() == Password) {
					UsersFile.close();
					return User;
				}
				vUser.push_back(User);
			}

			UsersFile.close();

		}

		return _GetEmptyUserObject();

	}

	static bool isUserExist(string UserName) {

		clsUser User = clsUser::Find(UserName);
		return (!User.isEmpty());

	}

	enum enSaveResult { svFailed = 0, svSucceeded = 1, svFailedAccNumExist = 2 };

	enSaveResult Save() {

		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (isEmpty()) {
				return enSaveResult::svFailed;
			}
			break;
		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;
			break;
		case enMode::AddNewMode:
			if (clsUser::isUserExist(_UserName))
			{

				return enSaveResult::svFailedAccNumExist;

			}
			else
			{
				_Add();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			return enSaveResult::svSucceeded;
			break;
		}

	}

	static clsUser CreateNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete() {

		vector <clsUser> vUser = _LoadUserDataFromFile();
		for (clsUser& User : vUser) {

			if (User.UserName() == UserName()) {
				User._MarkForDelete = true;
				break;
			}

		}

		_SaveUsersDataToFile(vUser);
		*this = _GetEmptyUserObject();
		return true;
	}

	static vector <clsUser> GetUsersList() {
		return _LoadUserDataFromFile();
	}

	bool CheckAccessPermissions(enPermission Permission) {

		if (this->Permission() == enPermission::pAll)
			return true;

		if ((Permission & this->Permission()) == Permission)
			return true;
		else
			return false;

	}

	void SaveLog() {

		fstream LogFile;

		LogFile.open("LogRegister.txt", ios::out | ios::app);

		if (LogFile.is_open()) {

			string Line = _ConvertLogDataToLine(*this);

			LogFile << Line << endl;


		}

		LogFile.close();

	}

};

