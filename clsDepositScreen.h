#pragma once
class clsDepositScreen
{

public:

	static void _PrintClient(clsBankClient Client) {

		cout << "\nClient Card: " << endl;
		cout << "---------------------------------------" << endl;
		cout << "Acc. Number: " << Client.AccountNumber() << endl;
		cout << "First Name : " << Client.FirstName() << endl;
		cout << "Last Name  : " << Client.LastName() << endl;
		cout << "Full Name  : " << Client.FullName() << endl;
		cout << "Email      : " << Client.Email() << endl;
		cout << "Phone      : " << Client.PhoneNumber() << endl;
		cout << "Balance    : " << Client.GetBalance() << endl;
		cout << "---------------------------------------" << endl;

	}

public:

	static void ShowDepositScreen() {

		clsScreen::DrawHeader();

		cout << endl;
		cout << setw(40) << left << "" << "________________________________________________\n" << endl;
		cout << setw(30) << left << "" << "\t\t\t            Deposit" << endl;
		cout << setw(40) << left << "" << "________________________________________________\n\n\n" << endl;

		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("Enter Account Number: ");

		while (!clsBankClient::isClientExist(AccountNumber))
		{

			cout << "\nAccount Number is Not Found!" << endl;
			AccountNumber = clsInputValidate::ReadString("Enter Another Account Number: ");

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << setw(40) << left << "";
		double Amount = clsInputValidate::ReadDblNumber("Enter Deposit Amount: ", "Invalid Amount, Try Again: ");

		cout << "Are you sure you want to perform this action? (Y/N)? ";
		char Answer = 'Y';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {

			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully!" << endl;
			cout << "New Balance is: " << Client.Balance << endl;

		}
		else {
			cout << "Operation Was Cancelled." << endl;
		}

	}
};

