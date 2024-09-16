#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "../OOP_C++/clsInputValidate.h"
#include "../OOP_C++/clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };

	enMode _Mode;
	string _AccountNumber;
	string _PINCode;
	float _Balance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {

		vector <string> Client = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, Client[0], Client[1], Client[2], Client[3], Client[4], Client[5], stof(Client[6]));
	}

	static vector <clsBankClient> _LoadClientsDataFromFile() {

		vector <clsBankClient> vClients;
		fstream ClientsFile;

		ClientsFile.open("Clients.txt", ios::in);

		if (ClientsFile.is_open()) {

			string Line;
			while (getline(ClientsFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			ClientsFile.close();

		}

		return vClients;

	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {

		string stClientRecord = "";
		stClientRecord += Client.FirstName() + Seperator;
		stClientRecord += Client.LastName() + Seperator;
		stClientRecord += Client.Email() + Seperator;
		stClientRecord += Client.PhoneNumber() + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PINCode + Seperator;
		stClientRecord += to_string(Client.Balance);

		return stClientRecord;

	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {

		fstream ClientsFile;

		ClientsFile.open("Clients.txt", ios::out);

		string DataLine;

		if (ClientsFile.is_open()) {

			for (clsBankClient C : vClients) {

				if (C.MarkForDelete() == false) {
					DataLine = _ConvertClientObjectToLine(C);
					ClientsFile << DataLine << endl;
				}

			}

			ClientsFile.close();

		}


	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _Update() {

		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients) {

			if (C.AccountNumber() == AccountNumber()) {

				C = *this;
				break;

			}

		}

		_SaveClientsDataToFile(vClients);
		

	}

	void _Add() {

		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		clsBankClient Client = *this;
		vClients.push_back(Client);
		_SaveClientsDataToFile(vClients);
		
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string AccountNumber, string PINCode, float Balance) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PINCode = PINCode;
		_Balance = Balance;

	}

	bool isEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPINCode(string PIN) {
		_PINCode = PIN;
	}

	string GetPINCode() {
		return _PINCode;
	}

	__declspec(property(get = GetPINCode, put = SetPINCode)) string PINCode;

	void SetBalance(float Balance) {
		_Balance = Balance;
	}

	float GetBalance() {
		return _Balance;
	}

	__declspec(property(get = GetBalance, put = SetBalance)) float Balance;

	static clsBankClient Find(string AccountNumber) {

		vector <clsBankClient> vClients;
		fstream ClientsFile;

		ClientsFile.open("Clients.txt", ios::in);

		if (ClientsFile.is_open()) {

			string Line;
			while (getline(ClientsFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber) {
					ClientsFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			ClientsFile.close();

		}

		return _GetEmptyClientObject();

	}

	static clsBankClient Find(string AccountNumber, string PIN) {

		vector <clsBankClient> vClients;
		fstream ClientsFile;

		ClientsFile.open("Clients.txt", ios::in);

		if (ClientsFile.is_open()) {

			string Line;
			while (getline(ClientsFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PINCode == PIN) {
					ClientsFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			ClientsFile.close();

		}

		return _GetEmptyClientObject();

	}

	static bool isClientExist(string AccountNumber) {

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.isEmpty());

	}

	enum enSaveResult { svFailed = 0, svSucceeded = 1 , svFailedAccNumExist = 2 };

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
			if (clsBankClient::isClientExist(_AccountNumber))
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

	static clsBankClient CreateNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {

		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& Client : vClients) {

			if (Client.AccountNumber() == AccountNumber()) {
				Client._MarkForDelete = true;
				break;
			}

		}

		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances() {

		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		double TotalBalances = 0;

		for (clsBankClient& Client : vClients) {

			TotalBalances += Client.Balance;

		}

		return TotalBalances;

	}

	void Deposit(double Amount) {

		_Balance += Amount;
		Save();

	}

	bool Withdraw(double Amount) {

		if (Amount > _Balance) {
			return false;
		}
		else {
			_Balance -= Amount;
			Save();
		}
		return true;
	}

	bool Transfer(float Amount, clsBankClient& DesClient) {

		if (Amount > Balance) {
			return false;
		}

		Withdraw(Amount);
		DesClient.Deposit(Amount);
		return true;

	}

};