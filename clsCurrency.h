#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include "../OOP_C++/clsString.h"
using namespace std;

const string FileName = "Currencies.txt";

class clsCurrency
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _CountryName;
	string _CountryCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToObject(string Line, string Delim = "#//#") {

		vector <string> vCurr = clsString::Split(Line, Delim);

		return clsCurrency(enMode::UpdateMode, vCurr[0], vCurr[1], vCurr[2], stof(vCurr[3]));

	}
	
	static vector <clsCurrency> _LoadCurrenciesDataFromFile() {

		vector <clsCurrency> vCurr;
		fstream File;

		File.open(FileName, ios::in);

		if (File.is_open()) {

			string Line;
			while (getline(File, Line))
			{

				clsCurrency Curr = _ConvertLineToObject(Line);
				vCurr.push_back(Curr);

			}
			
			File.close();

		}

		return vCurr;

	}

	static string _ConvertObjectToLine(clsCurrency Curr, string Delim = "#//#") {
		
		string Record = "";
		Record += Curr.CountryName() + Delim;
		Record += Curr.CountryCode() + Delim;
		Record += Curr.CurrencyName() + Delim;
		Record += to_string(Curr.Rate()) + Delim;

		return Record;

	}

	static void _SaveDataToFile(vector <clsCurrency> vCurr) {

		fstream File;

		File.open(FileName, ios::out);

		if (File.is_open()) {

			for (clsCurrency &Curr : vCurr)
			{

				string Record = _ConvertObjectToLine(Curr);
				File << Record << endl;

			}

			File.close();

		}

	}

	void _Update() {

		vector <clsCurrency> vCurr = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Curr : vCurr) {

			if (Curr.CountryCode() == CountryCode()) {
				Curr = *this;
				break;
			}

		}

		_SaveDataToFile(vCurr);

	}

public:

	clsCurrency(enMode Mode, string CountryName, string CountryCode, string CurrencyName, float Rate) {
		_CountryName = CountryName;
		_CountryCode = CountryCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
		_Mode = Mode;
	}

	bool isEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string CountryName() {
		return _CountryName;
	}

	string CountryCode() {
		return _CountryCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}

	float Rate() {
		return _Rate;
	}

	static clsCurrency FindByCode(string Code) {

		Code = clsString::UpperAllString(Code);

		vector <clsCurrency> vCurr = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Curr : vCurr) {

			if (Curr.CountryCode() == Code) {
				return Curr;
			}

		}

		return clsCurrency(enMode::EmptyMode, "", "", "", 0);

	}

	static clsCurrency FindByCountry(string Country) {

		Country = clsString::UpperAllString(Country);

		vector <clsCurrency> vCurr = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Curr : vCurr) {

			if (clsString::UpperAllString(Curr.CountryName()) == Country) {
				return Curr;
			}

		}

		return clsCurrency(enMode::EmptyMode, "", "", "", 0);

	}

	static bool isCurrencyExist(string Code) {

		Code = clsString::UpperAllString(Code);

		vector <clsCurrency> vCurr = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Curr : vCurr) {

			if (Curr.CountryCode() == Code) {
				return true;
			}

		}

		return false;

	}

	static vector <clsCurrency> GetCurrencyList() {
		return _LoadCurrenciesDataFromFile();
	}

	static clsCurrency GetEmptyCurrency() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	float ConvertToUSD(float Amount) {

		return (float)(Amount / Rate());

	}

	float ConvertToOtherCountry(float Amount, clsCurrency Country) {

		float AmountInUSD = ConvertToUSD(Amount);

		if (Country.CountryCode() == "USD") {
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Country.Rate());

	}

};

